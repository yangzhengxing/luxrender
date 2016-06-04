/***************************************************************************
* Copyright 1998-2015 by authors (see AUTHORS.txt)                        *
*                                                                         *
*   This file is part of LuxRender.                                       *
*                                                                         *
* Licensed under the Apache License, Version 2.0 (the "License");         *
* you may not use this file except in compliance with the License.        *
* You may obtain a copy of the License at                                 *
*                                                                         *
*     http://www.apache.org/licenses/LICENSE-2.0                          *
*                                                                         *
* Unless required by applicable law or agreed to in writing, software     *
* distributed under the License is distributed on an "AS IS" BASIS,       *
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*
* See the License for the specific language governing permissions and     *
* limitations under the License.                                          *
***************************************************************************/
#include "LR_Light.h"
#include "maxscript\maxscript.h"

#define LR_Light_CLASS_ID	Class_ID(0x5d2f7ac1, 0x7dd93354)


#define NUM_SUBMATERIALS 1
#define PBLOCK_REF NUM_SUBMATERIALS

class LR_Light : public Mtl {
public:
	LR_Light();
	LR_Light(BOOL loading);
	~LR_Light();


	ParamDlg* CreateParamDlg(HWND hwMtlEdit, IMtlParams* imp);
	void      Update(TimeValue t, Interval& valid);
	Interval  Validity(TimeValue t);
	void      Reset();

	void NotifyChanged();

	// From MtlBase and Mtl
	virtual void SetAmbient(Color c, TimeValue t);
	virtual void SetDiffuse(Color c, TimeValue t);
	virtual void SetSpecular(Color c, TimeValue t);
	virtual void SetShininess(float v, TimeValue t);
	virtual Color GetAmbient(int mtlNum=0, BOOL backFace=FALSE);
	virtual Color GetDiffuse(int mtlNum=0, BOOL backFace=FALSE);
	virtual Color GetSpecular(int mtlNum=0, BOOL backFace=FALSE);
	virtual float GetXParency(int mtlNum=0, BOOL backFace=FALSE);
	virtual float GetShininess(int mtlNum=0, BOOL backFace=FALSE);
	virtual float GetShinStr(int mtlNum=0, BOOL backFace=FALSE);
	virtual float WireSize(int mtlNum=0, BOOL backFace=FALSE);


	// Shade calculation
	virtual void     Shade(ShadeContext& sc);

	// SubMaterial access methods
	//virtual int  NumSubMtls() {return NUM_SUBMATERIALS;}
	virtual int  NumSubMtls() { return 0; }
	virtual Mtl* GetSubMtl(int i);
	virtual void SetSubMtl(int i, Mtl *m);
	virtual TSTR GetSubMtlSlotName(int i);
	virtual TSTR GetSubMtlTVName(int i);

	// SubTexmap access methods
	virtual int     NumSubTexmaps() {return 0;}
	virtual Texmap* GetSubTexmap(int i);
	virtual void    SetSubTexmap(int i, Texmap *m);
	virtual TSTR    GetSubTexmapSlotName(int i);
	virtual TSTR    GetSubTexmapTVName(int i);

	virtual BOOL SetDlgThing(ParamDlg* dlg);

	// Loading/Saving
	virtual IOResult Load(ILoad *iload);
	virtual IOResult Save(ISave *isave);

	// From Animatable
	virtual Class_ID ClassID() {return LR_Light_CLASS_ID;}
	virtual SClass_ID SuperClassID() { return MATERIAL_CLASS_ID; }
	virtual void GetClassName(TSTR& s) {s = GetString(IDS_CLASS_NAME);}

	virtual RefTargetHandle Clone( RemapDir &remap );
	virtual RefResult NotifyRefChanged(const Interval& changeInt, RefTargetHandle hTarget, PartID& partID, RefMessage message, BOOL propagate);

	virtual int NumSubs() { return 1+NUM_SUBMATERIALS; }
	virtual Animatable* SubAnim(int i);
	virtual TSTR SubAnimName(int i);

	// TODO: Maintain the number or references here
	virtual int NumRefs() { return 1 + NUM_SUBMATERIALS; }
	virtual RefTargetHandle GetReference(int i);

	virtual int NumParamBlocks() { return 1; }					  // return number of ParamBlocks in this instance
	virtual IParamBlock2* GetParamBlock(int /*i*/) { return pblock; } // return i'th ParamBlock
	virtual IParamBlock2* GetParamBlockByID(BlockID id) { return (pblock->ID() == id) ? pblock : NULL; } // return id'd ParamBlock

	virtual void DeleteThis() { delete this; }

protected:
	virtual void SetReference(int i, RefTargetHandle rtarg);

private:
	Mtl*          submtl[NUM_SUBMATERIALS];  // Fixed size Reference array of sub-materials. (Indexes: 0-(N-1))
	IParamBlock2* pblock;					 // Reference that comes AFTER the sub-materials. (Index: N)
	
	BOOL          mapOn[NUM_SUBMATERIALS];
	Interval      ivalid;
};



class LR_LightClassDesc : public ClassDesc2 
{
public:
	virtual int IsPublic() 							{ return TRUE; }
	virtual void* Create(BOOL loading = FALSE) 		{ return new LR_Light(loading); }
	virtual const TCHAR *	ClassName() 			{ return GetString(IDS_CLASS_NAME); }
	virtual SClass_ID SuperClassID() 				{ return MATERIAL_CLASS_ID; }
	virtual Class_ID ClassID() 						{ return LR_Light_CLASS_ID; }
	virtual const TCHAR* Category() 				{ return GetString(IDS_CATEGORY); }

	virtual const TCHAR* InternalName() 			{ return _T("LR_Light"); }	// returns fixed parsable name (scripter-visible name)
	virtual HINSTANCE HInstance() 					{ return hInstance; }					// returns owning module handle
	

};


ClassDesc2* GetLR_LightDesc() { 
	static LR_LightClassDesc LR_LightDesc;
	return &LR_LightDesc; 
}





enum { LR_Light_params };


//TODO: Add enums for various parameters
enum { 
	pb_Dummy,
	pb_Dummy1,
	pb_Dummy2,
	prm_color,
};




static ParamBlockDesc2 LR_Light_param_blk ( LR_Light_params, _T("params"),  0, GetLR_LightDesc(), 
	P_AUTO_CONSTRUCT + P_AUTO_UI, PBLOCK_REF, 
	//rollout
	IDD_PANEL, IDS_PARAMS, 0, 0, NULL,
	// params
	prm_color,			_T("color"),			TYPE_RGBA,	P_ANIMATABLE,		IDS_COLOR,
		p_default, Color(0.5f, 0.5f, 0.5f),
		p_ui,			TYPE_COLORSWATCH, IDC_SAMP_COLOR,
		p_end,
	p_end
	);




LR_Light::LR_Light()
	: pblock(nullptr)
{
	for (int i=0; i<NUM_SUBMATERIALS; i++) 
		submtl[i] = nullptr;
	Reset();
}

LR_Light::LR_Light(BOOL loading)
	: pblock(nullptr)
{
	for (int i=0; i<NUM_SUBMATERIALS; i++) 
		submtl[i] = nullptr;
	
	if (!loading)
		Reset();
}

LR_Light::~LR_Light()
{
	DeleteAllRefs();
}


void LR_Light::Reset()
{
	ivalid.SetEmpty();
	// Always have to iterate backwards when deleting references.
	for (int i = NUM_SUBMATERIALS - 1; i >= 0; i--) {
		if( submtl[i] ){
			DeleteReference(i);
			DbgAssert(submtl[i] == nullptr);
			submtl[i] = nullptr;
		}
		mapOn[i] = FALSE;
	}
	DeleteReference(PBLOCK_REF);

	GetLR_LightDesc()->MakeAutoParamBlocks(this);
}



ParamDlg* LR_Light::CreateParamDlg(HWND hwMtlEdit, IMtlParams *imp)
{
	ExecuteMAXScriptScript(L"mental_ray_Preferences.mrExtensionsActive = false");
	IAutoMParamDlg* masterDlg = GetLR_LightDesc()->CreateParamDlgs(hwMtlEdit, imp, this);
	// TODO: Set param block user dialog if necessary
	return masterDlg;
}

BOOL LR_Light::SetDlgThing(ParamDlg* /*dlg*/)
{
	return FALSE;
}

Interval LR_Light::Validity(TimeValue t)
{
	Interval valid = FOREVER;

	for (int i = 0; i < NUM_SUBMATERIALS; i++)
	{
		if (submtl[i])
			valid &= submtl[i]->Validity(t);
	}

	return valid;
}

/*===========================================================================*\
 |	Sub-anim & References support
\*===========================================================================*/

RefTargetHandle LR_Light::GetReference(int i)
{
	if ((i >= 0) && (i < NUM_SUBMATERIALS))
		return submtl[i];
	else if (i == PBLOCK_REF)
		return pblock;
	else
		return nullptr;
}

void LR_Light::SetReference(int i, RefTargetHandle rtarg)
{
	if ((i >= 0) && (i < NUM_SUBMATERIALS))
		submtl[i] = (Mtl *)rtarg;
	else if (i == PBLOCK_REF)
	{
		pblock = (IParamBlock2 *)rtarg;
	}
}

TSTR LR_Light::SubAnimName(int i)
{
	if ((i >= 0) && (i < NUM_SUBMATERIALS))
		return GetSubMtlTVName(i);
	else 
		return TSTR(_T(""));
}

Animatable* LR_Light::SubAnim(int i)
{
	if ((i >= 0) && (i < NUM_SUBMATERIALS))
		return submtl[i];
	else if (i == PBLOCK_REF)
		return pblock;
	else
		return nullptr;
}

RefResult LR_Light::NotifyRefChanged(const Interval& /*changeInt*/, RefTargetHandle hTarget, 
	PartID& /*partID*/, RefMessage message, BOOL /*propagate*/ ) 
{
	switch (message) {
	case REFMSG_CHANGE:
		{
			ivalid.SetEmpty();
			if (hTarget == pblock)
			{
				ParamID changing_param = pblock->LastNotifyParamID();
				LR_Light_param_blk.InvalidateUI(changing_param);
			}
		}
		break;
	case REFMSG_TARGET_DELETED:
		{
			if (hTarget == pblock)
			{
				pblock = nullptr;
			} 
			else
			{
				for (int i = 0; i < NUM_SUBMATERIALS; i++)
				{
					if (hTarget == submtl[i])
					{
						submtl[i] = nullptr;
						break;
					}
				}
			}
			break;
		}
	}
	return REF_SUCCEED;
}

/*===========================================================================*\
 |	SubMtl get and set
\*===========================================================================*/

Mtl* LR_Light::GetSubMtl(int i)
{
	if ((i >= 0) && (i < NUM_SUBMATERIALS))
		return submtl[i];
	return 
		nullptr;
}

void LR_Light::SetSubMtl(int i, Mtl* m)
{
	ReplaceReference(i,m);
	// TODO: Set the material and update the UI
}

TSTR LR_Light::GetSubMtlSlotName(int)
{
	// Return i'th sub-material name
	return _T("");
}

TSTR LR_Light::GetSubMtlTVName(int i)
{
	return GetSubMtlSlotName(i);
}

/*===========================================================================*\
 |	Texmap get and set
 |  By default, we support none
\*===========================================================================*/

Texmap* LR_Light::GetSubTexmap(int /*i*/)
{
	return nullptr;
}

void LR_Light::SetSubTexmap(int /*i*/, Texmap* /*m*/)
{
}

TSTR LR_Light::GetSubTexmapSlotName(int /*i*/)
{
	return _T("");
}

TSTR LR_Light::GetSubTexmapTVName(int i)
{
	// Return i'th sub-texture name
	return GetSubTexmapSlotName(i);
}



/*===========================================================================*\
 |	Standard IO
\*===========================================================================*/

#define MTL_HDR_CHUNK 0x4000

IOResult LR_Light::Save(ISave* isave)
{
	IOResult res;
	isave->BeginChunk(MTL_HDR_CHUNK);
	res = MtlBase::Save(isave);
	if (res!=IO_OK) 
		return res;
	isave->EndChunk();

	return IO_OK;
}

IOResult LR_Light::Load(ILoad* iload)
{
	IOResult res;
	while (IO_OK==(res=iload->OpenChunk()))
	{
		int id = iload->CurChunkID();
		switch(id)
		{
		case MTL_HDR_CHUNK:
			res = MtlBase::Load(iload);
			break;
		}

		iload->CloseChunk();
		if (res!=IO_OK)
			return res;
	}

	return IO_OK;
}


/*===========================================================================*\
 |	Updating and cloning
\*===========================================================================*/

RefTargetHandle LR_Light::Clone(RemapDir &remap)
{
	LR_Light *mnew = new LR_Light(FALSE);
	*((MtlBase*)mnew) = *((MtlBase*)this);
	// First clone the parameter block
	mnew->ReplaceReference(PBLOCK_REF,remap.CloneRef(pblock));
	// Next clone the sub-materials
	mnew->ivalid.SetEmpty();
	for (int i = 0; i < NUM_SUBMATERIALS; i++) {
		mnew->submtl[i] = nullptr;
		if (submtl[i])
			mnew->ReplaceReference(i,remap.CloneRef(submtl[i]));
		mnew->mapOn[i] = mapOn[i];
		}
	BaseClone(this, mnew, remap);
	return (RefTargetHandle)mnew;
	}

void LR_Light::NotifyChanged()
{
	NotifyDependents(FOREVER, PART_ALL, REFMSG_CHANGE);
}

void LR_Light::Update(TimeValue t, Interval& valid)
{
	if (!ivalid.InInterval(t)) {

		ivalid.SetInfinite();

		for (int i=0; i < NUM_SUBMATERIALS; i++) {
			if (submtl[i])
				submtl[i]->Update(t,ivalid);
			}
		}
	valid &= ivalid;
}

/*===========================================================================*\
 |	Determine the characteristics of the material
\*===========================================================================*/

void LR_Light::SetAmbient(Color /*c*/, TimeValue /*t*/) {}		
void LR_Light::SetDiffuse(Color /*c*/, TimeValue /*t*/) {}		
void LR_Light::SetSpecular(Color /*c*/, TimeValue /*t*/) {}
void LR_Light::SetShininess(float /*v*/, TimeValue /*t*/) {}

Color LR_Light::GetAmbient(int mtlNum, BOOL backFace)
{
	Point3 p;
	//TimeValue t; //Zero for first frame //GetCOREInterface()->GetTime() for every frame
	pblock->GetValue(prm_color, GetCOREInterface()->GetTime(), p, ivalid);
	return submtl[0] ? submtl[0]->GetAmbient(mtlNum, backFace) : Color(p.x, p.y, p.z);//Bound(Color(p.x, p.y, p.z));
}

Color LR_Light::GetDiffuse(int mtlNum, BOOL backFace)
{
	Point3 p;
	//TimeValue t; //Zero for first frame //GetCOREInterface()->GetTime() for every frame
	pblock->GetValue(prm_color, 0, p, ivalid);
	return submtl[0] ? submtl[0]->GetDiffuse(mtlNum, backFace) : Color(p.x, p.y, p.z);
}

Color LR_Light::GetSpecular(int mtlNum, BOOL backFace)
{
	return submtl[0] ? submtl[0]->GetSpecular(mtlNum,backFace): Color(1,1,1);
}

float LR_Light::GetXParency(int mtlNum, BOOL backFace)
{
	return submtl[0] ? submtl[0]->GetXParency(mtlNum,backFace): 0.0f;
}

float LR_Light::GetShininess(int mtlNum, BOOL backFace)
{
	return submtl[0] ? submtl[0]->GetShininess(mtlNum,backFace): 1.0f;
}

float LR_Light::GetShinStr(int mtlNum, BOOL backFace)
{
	return submtl[0] ? submtl[0]->GetShinStr(mtlNum,backFace): 0.0f;
}

float LR_Light::WireSize(int mtlNum, BOOL backFace)
{
	return submtl[0] ? submtl[0]->WireSize(mtlNum,backFace): 0.0f;
}


/*===========================================================================*\
 |	Actual shading takes place
\*===========================================================================*/

void LR_Light::Shade(ShadeContext& sc)
{
	Mtl* subMaterial = mapOn[0] ? submtl[0] : nullptr;
	if (gbufID) 
		sc.SetGBufferID(gbufID);

	if(subMaterial) 
		subMaterial->Shade(sc);
	// TODO: compute the color and transparency output returned in sc.out.
}
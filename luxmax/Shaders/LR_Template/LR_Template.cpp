//**************************************************************************/
// Copyright (c) 1998-2007 Autodesk, Inc.
// All rights reserved.
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information written by Autodesk, Inc., and are
// protected by Federal copyright law. They may not be disclosed to third
// parties or copied or duplicated in any form, in whole or in part, without
// the prior written consent of Autodesk, Inc.
//**************************************************************************/
// DESCRIPTION: Appwizard generated plugin
// AUTHOR:
//***************************************************************************/

#include "LR_Template.h"
#include <maxscript\maxscript.h>

#define LR_Template_CLASS_ID	Class_ID(0x64691d17, 0x288d50d9)


#define NUM_SUBMATERIALS 1 // TODO: number of sub-materials supported by this plug-in
#define NUM_SUBTEXTURES 1
#define Num_REF 2 
// Reference Indexes
// 
#define PBLOCK_REF 1

class LR_Template : public Mtl {
public:
	LR_Template();
	LR_Template(BOOL loading);
	~LR_Template();


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


	// Shade and displacement calculation
	virtual void     Shade(ShadeContext& sc);
	virtual float    EvalDisplacement(ShadeContext& sc);
	virtual Interval DisplacementValidity(TimeValue t);

	// SubMaterial access methods
	virtual int  NumSubMtls() {return NUM_SUBMATERIALS;}
	virtual Mtl* GetSubMtl(int i);
	virtual void SetSubMtl(int i, Mtl *m);
	virtual TSTR GetSubMtlSlotName(int i);
	virtual TSTR GetSubMtlTVName(int i);

	// SubTexmap access methods
	virtual int     NumSubTexmaps() { return NUM_SUBTEXTURES; }
	virtual Texmap* GetSubTexmap(int i);
	virtual void    SetSubTexmap(int i, Texmap *tx);
	virtual TSTR    GetSubTexmapSlotName(int i);
	virtual TSTR    GetSubTexmapTVName(int i);

	virtual BOOL SetDlgThing(ParamDlg* dlg);

	// Loading/Saving
	virtual IOResult Load(ILoad *iload);
	virtual IOResult Save(ISave *isave);

	// From Animatable
	virtual Class_ID ClassID() {return LR_Template_CLASS_ID;}
	virtual SClass_ID SuperClassID() { return MATERIAL_CLASS_ID; }
	virtual void GetClassName(TSTR& s) {s = GetString(IDS_CLASS_NAME);}

	virtual RefTargetHandle Clone( RemapDir &remap );
	virtual RefResult NotifyRefChanged(const Interval& changeInt, RefTargetHandle hTarget, PartID& partID, RefMessage message, BOOL propagate);

	virtual int NumSubs() { return 1+NUM_SUBMATERIALS; }
	virtual Animatable* SubAnim(int i);
	virtual TSTR SubAnimName(int i);

	// TODO: Maintain the number or references here
	virtual int NumRefs() { return 1 + Num_REF; }
	virtual RefTargetHandle GetReference(int i);

	virtual int NumParamBlocks() { return 1; }					  // return number of ParamBlocks in this instance
	virtual IParamBlock2* GetParamBlock(int /*i*/) { return pblock; } // return i'th ParamBlock
	virtual IParamBlock2* GetParamBlockByID(BlockID id) { return (pblock->ID() == id) ? pblock : NULL; } // return id'd ParamBlock

	virtual void DeleteThis() { delete this; }

protected:
	virtual void SetReference(int i, RefTargetHandle rtarg);

private:
	Mtl*          submtl[NUM_SUBMATERIALS];  // Fixed size Reference array of sub-materials. (Indexes: 0-(N-1))
	Texmap*       subtexture[NUM_SUBTEXTURES];
	IParamBlock2* pblock;					 // Reference that comes AFTER the sub-materials. (Index: N)
	
	BOOL          mapOn[NUM_SUBMATERIALS];
	float         spin;
	Interval      ivalid;
	Interval	  mapValid;
};



class LR_TemplateClassDesc : public ClassDesc2 
{
public:
	virtual int IsPublic() 							{ return TRUE; }
	virtual void* Create(BOOL loading = FALSE) 		{ return new LR_Template(loading); }
	virtual const TCHAR *	ClassName() 			{ return GetString(IDS_CLASS_NAME); }
	virtual SClass_ID SuperClassID() 				{ return MATERIAL_CLASS_ID; }
	virtual Class_ID ClassID() 						{ return LR_Template_CLASS_ID; }
	virtual const TCHAR* Category() 				{ return GetString(IDS_CATEGORY); }

	virtual const TCHAR* InternalName() 			{ return _T("LR_Template"); }	// returns fixed parsable name (scripter-visible name)
	virtual HINSTANCE HInstance() 					{ return hInstance; }					// returns owning module handle
	

};


ClassDesc2* GetLR_TemplateDesc() { 
	static LR_TemplateClassDesc LR_TemplateDesc;
	return &LR_TemplateDesc; 
}





enum { LR_Template_params };


//TODO: Add enums for various parameters
enum {
	pb_spin,
	mtl_mat1,
	mtl_mat1_on,
	prm_color,
	mtl_map,
	prm_ambientcolor,
	pb_opacity,
	prm_spec,
	pb_shin,
	pb_wiresize,
};




static ParamBlockDesc2 LR_Template_param_blk (
	LR_Template_params, _T("params"),  0, GetLR_TemplateDesc(),	P_AUTO_CONSTRUCT + P_AUTO_UI, PBLOCK_REF, 
	//rollout
	IDD_PANEL, IDS_PARAMS, 0, 0, NULL,
	// params
	pb_spin, 			_T("spin"), 			TYPE_FLOAT, 	P_ANIMATABLE, 	IDS_SPIN,
		p_default, 		0.1f, 
		p_range, 		0.0f,1000.0f, 
		p_ui, 			TYPE_SPINNER,			EDITTYPE_FLOAT, IDC_EDIT,	IDC_SPIN, 0.01f, 
		p_end,
	mtl_mat1,			_T("mtl_mat1"),			TYPE_MTL,	P_OWNERS_REF,		IDS_MTL1,
		p_refno,		0,
		p_submtlno,		0,		
		p_ui,			TYPE_MTLBUTTON,			IDC_MTL1,
		p_end,
	mtl_mat1_on,		_T("mtl_mat1_on"),		TYPE_BOOL,		0,				IDS_MTL1ON,
		p_default,		TRUE,
		p_ui,			TYPE_SINGLECHEKBOX,		IDC_MTLON1,
		p_end,
	prm_color,			_T("Diffuse"),			TYPE_RGBA,	P_ANIMATABLE,		IDS_COLOR,
		p_default, Color(0.5f, 0.5f, 0.5f),
		p_ui,			TYPE_COLORSWATCH,		IDC_SAMP_COLOR,
		p_end,
	mtl_map,		_T("diffuseMap"),		TYPE_TEXMAP,	P_OWNERS_REF,		IDS_MAP,
		p_refno,		2,
		p_subtexno,		0,
		p_ui,			TYPE_TEXMAPBUTTON,		IDC_SAMP_MAP,
		p_end,
	prm_ambientcolor,	_T("color"),			TYPE_RGBA,	P_ANIMATABLE,		IDS_COLOR2,
		p_default, Color(0.0f, 0.0f, 0.0f),
		p_ui,			TYPE_COLORSWATCH,		IDC_SAMP_COLOR2,
		p_end,
	pb_opacity,			_T("spin"),				TYPE_FLOAT,	P_ANIMATABLE,		IDS_SPIN2,
		p_default, 0.0f,
		p_range, 0.0f, 1.0f,
		p_ui,			TYPE_SPINNER,			EDITTYPE_FLOAT,	IDC_EDIT2,	IDC_SPIN2, 0.01f,
		p_end,
	prm_spec,			_T("color"),			TYPE_FLOAT, P_ANIMATABLE,		IDS_COLOR3,
		p_default,	Color(1.0f, 1.0f, 1.0f),
		p_ui,			TYPE_COLORSWATCH,		IDC_SAMP_COLOR3,
		p_end,
	pb_shin,			_T("spin"),				TYPE_FLOAT, P_ANIMATABLE,		IDS_SPIN4,
		p_default, 0.0f,
		p_range, 0.0f, 1.0f,
		p_ui,			TYPE_SPINNER,			EDITTYPE_FLOAT, IDC_EDIT4,	IDC_SPIN4, 0.01f,
		p_end,
	pb_wiresize,		_T("spin"),				TYPE_FLOAT, P_ANIMATABLE,		IDS_SPIN6,
		p_default, 0.0f,
		p_range, 0.0f, 100.0f,
		p_ui,			TYPE_SPINNER,			EDITTYPE_FLOAT, IDC_EDIT6,	IDC_SPIN6, 0.01f,
		p_end,
	p_end
	);




LR_Template::LR_Template()
	: pblock(nullptr)
{
	for (int i = 0; i < NUM_SUBMATERIALS; i++)
	{
		submtl[i] = nullptr;
		subtexture[i] = nullptr;
	}
	Reset();
}

LR_Template::LR_Template(BOOL loading)
	: pblock(nullptr)
{
	for (int i = 0; i < NUM_SUBMATERIALS; i++)
	{
		submtl[i] = nullptr;
		subtexture[i] = nullptr;
	}
	
	if (!loading)
		Reset();
}

LR_Template::~LR_Template()
{
	DeleteAllRefs();
}


void LR_Template::Reset()
{
	ivalid.SetEmpty();
	mapValid.SetEmpty();
	// Always have to iterate backwards when deleting references.
	for (int i = NUM_SUBMATERIALS - 1; i >= 0; i--)
	{
		if( submtl[i] )
		{
			DeleteReference(i);
			DbgAssert(submtl[i] == nullptr);
			submtl[i] = nullptr;
		}
		if (subtexture[i])
		{
			DeleteReference(i);
			DbgAssert(subtexture[i] == nullptr);
			subtexture[i] = nullptr;
		}
		mapOn[i] = FALSE;
	}
	DeleteReference(PBLOCK_REF);

	GetLR_TemplateDesc()->MakeAutoParamBlocks(this);
}



ParamDlg* LR_Template::CreateParamDlg(HWND hwMtlEdit, IMtlParams *imp)
{
	ExecuteMAXScriptScript(L"mental_ray_Preferences.mrExtensionsActive = false");
	IAutoMParamDlg* masterDlg = GetLR_TemplateDesc()->CreateParamDlgs(hwMtlEdit, imp, this);
	// TODO: Set param block user dialog if necessary
	return masterDlg;
}

BOOL LR_Template::SetDlgThing(ParamDlg* /*dlg*/)
{
	return FALSE;
}

Interval LR_Template::Validity(TimeValue t)
{
	Interval valid = FOREVER;

	for (int i = 0; i < NUM_SUBMATERIALS; i++)
	{
		if (submtl[i])
			valid &= submtl[i]->Validity(t);
		if (subtexture[i])
			valid &= subtexture[i]->Validity(t);
	}
	float u;
	pblock->GetValue(pb_spin,t,u,valid);
	return valid;
}

/*===========================================================================*\
 |	Sub-anim & References support
\*===========================================================================*/

RefTargetHandle LR_Template::GetReference(int i)
{
	//mprintf(_T("\n GetReference Nubmer is : %i \n"), i);
	switch (i)
	{
		case 0: return submtl[i]; break;
		case 1: return pblock; break;
		default: return subtexture[i-2]; break;
	}
}

void LR_Template::SetReference(int i, RefTargetHandle rtarg)
{
	//mprintf(_T("\n SetReference Nubmer is : -> %i \n"), i);
	switch (i)
	{
		case 0: submtl[i] = (Mtl *)rtarg; break;
		case 1: pblock = (IParamBlock2 *)rtarg; break;
		default: subtexture[i-2] = (Texmap *)rtarg; break;
	}
}

TSTR LR_Template::SubAnimName(int i)
{
	if ((i >= 0) && (i < NUM_SUBMATERIALS))
		return GetSubMtlTVName(i);
	else
		return GetSubTexmapTVName(i-2);
}

Animatable* LR_Template::SubAnim(int i)
{
	switch (i)
	{
	case 0: return submtl[i];
	case 1: return pblock;
	default: return subtexture[i - 2];
	}
}

RefResult LR_Template::NotifyRefChanged(const Interval& /*changeInt*/, RefTargetHandle hTarget, 
	PartID& /*partID*/, RefMessage message, BOOL /*propagate*/ ) 
{
	switch (message) {
	case REFMSG_CHANGE:
		{
		ivalid.SetEmpty();
		mapValid.SetEmpty();
			if (hTarget == pblock)
			{
				ParamID changing_param = pblock->LastNotifyParamID();
				LR_Template_param_blk.InvalidateUI(changing_param);
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
					if (hTarget == subtexture[i])
					{
						subtexture[i] = nullptr;
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

Mtl* LR_Template::GetSubMtl(int i)
{
	if ((i >= 0) && (i < NUM_SUBMATERIALS))
		return submtl[i];
	return 
		nullptr;
}

void LR_Template::SetSubMtl(int i, Mtl* m)
{
	//mprintf(_T("\n SetSubMtl Nubmer is : %i \n"), i);
	ReplaceReference(i , m);
	if (i == 0)
	{
		LR_Template_param_blk.InvalidateUI(mtl_map);
		mapValid.SetEmpty();
	}
}

TSTR LR_Template::GetSubMtlSlotName(int i)
{
	// Return i'th sub-material name
	switch (i)
	{
	case 0:
		return _T("SubMaterial");
	default:
		return _T("SubMaterial");
	}
}

TSTR LR_Template::GetSubMtlTVName(int i)
{
	return GetSubMtlSlotName(i);
}

/*===========================================================================*\
 |	Texmap get and set
\*===========================================================================*/

Texmap* LR_Template::GetSubTexmap(int i)
{
	//mprintf(_T("\n GetSubTexmap Nubmer ----------->>>  is : Get %i \n"), i);
	if ((i >= 0) && (i < NUM_SUBTEXTURES))
		return subtexture[i];
	return
		nullptr;
}

void LR_Template::SetSubTexmap(int i, Texmap* tx)
{
	//mprintf(_T("\n SetSubTexmap Nubmer ----------->>>  is : %i \n"), i);
	ReplaceReference(i +2, tx);
	if (i == 0)
	{
		LR_Template_param_blk.InvalidateUI(mtl_map);
		mapValid.SetEmpty();
	}
}

TSTR LR_Template::GetSubTexmapSlotName(int i)
{
	switch (i)
	{
	case 0:
		return _T("Diffuse map");
	case 1:
		return _T("Bump Map");
	default:
		return _T("Diffuse Map");
	}
}

TSTR LR_Template::GetSubTexmapTVName(int i)
{
	// Return i'th sub-texture name
	return GetSubTexmapSlotName(i);
}



/*===========================================================================*\
 |	Standard IO
\*===========================================================================*/

#define MTL_HDR_CHUNK 0x4000
#define PARAM2_CHUNK 0x1010

IOResult LR_Template::Save(ISave* isave)
{
	IOResult res;
	isave->BeginChunk(MTL_HDR_CHUNK);
	res = MtlBase::Save(isave);
	if (res!=IO_OK)
		return res;
	isave->EndChunk();

	return IO_OK;
}

IOResult LR_Template::Load(ILoad* iload)
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

RefTargetHandle LR_Template::Clone(RemapDir &remap)
{
	LR_Template *mnew = new LR_Template(FALSE);
	*((MtlBase*)mnew) = *((MtlBase*)this);
	// First clone the parameter block
	mnew->ReplaceReference(PBLOCK_REF,remap.CloneRef(pblock));
	// Next clone the sub-materials
	mnew->ivalid.SetEmpty();
	mnew->mapValid.SetEmpty();
	for (int i = 0; i < NUM_SUBMATERIALS; i++) 
	{
		mnew->submtl[i] = nullptr;
		mnew->subtexture[i] = nullptr;
		if (submtl[i])
			mnew->ReplaceReference(i,remap.CloneRef(submtl[i]));
		if (subtexture[i])
			mnew->ReplaceReference(i+2, remap.CloneRef(subtexture[i]));
		mnew->mapOn[i] = mapOn[i];
	}
	BaseClone(this, mnew, remap);
	return (RefTargetHandle)mnew;
	}

void LR_Template::NotifyChanged()
{
	NotifyDependents(FOREVER, PART_ALL, REFMSG_CHANGE);
}

void LR_Template::Update(TimeValue t, Interval& valid)
{
	if (!ivalid.InInterval(t))
	{

		ivalid.SetInfinite();
		pblock->GetValue( mtl_mat1_on, t, mapOn[0], ivalid);
		pblock->GetValue( pb_spin, t, spin, ivalid);

		for (int i=0; i < NUM_SUBMATERIALS; i++)
		{
			if (submtl[i])
				submtl[i]->Update(t,ivalid);
		}
	}

	if (!mapValid.InInterval(t))
	{
		mapValid.SetInfinite();
		for (int i = 0; i<NUM_SUBTEXTURES; i++) {
			if (subtexture[i])
				subtexture[i]->Update(t, mapValid);
		}
	}

	valid &= mapValid;
	valid &= ivalid;
}

/*===========================================================================*\
 |	Determine the characteristics of the material
\*===========================================================================*/

void LR_Template::SetAmbient(Color /*c*/, TimeValue /*t*/) {}		
void LR_Template::SetDiffuse(Color /*c*/, TimeValue /*t*/) {}		
void LR_Template::SetSpecular(Color /*c*/, TimeValue /*t*/) {}
void LR_Template::SetShininess(float /*v*/, TimeValue /*t*/) {}

Color LR_Template::GetAmbient(int mtlNum, BOOL backFace)
{
	Point3 p;
	//TimeValue t; //Zero for first frame //GetCOREInterface()->GetTime() for every frame
	pblock->GetValue(prm_ambientcolor, GetCOREInterface()->GetTime(), p, ivalid);
	return submtl[0] ? submtl[0]->GetAmbient(mtlNum, backFace) : Color(p.x, p.y, p.z);//Bound(Color(p.x, p.y, p.z));
}

Color LR_Template::GetDiffuse(int mtlNum, BOOL backFace)
{
	Point3 p;
	//TimeValue t; //Zero for first frame //GetCOREInterface()->GetTime() for every frame
	pblock->GetValue(prm_color, 0, p, ivalid);
	return submtl[0] ? submtl[0]->GetDiffuse(mtlNum, backFace) : Color(p.x, p.y, p.z);
}

Color LR_Template::GetSpecular(int mtlNum, BOOL backFace)
{
	Point3 p;
	pblock->GetValue(prm_spec, 0, p, ivalid);
	return submtl[0] ? submtl[0]->GetSpecular(mtlNum,backFace): Color(p.x, p.y, p.z);
}

float LR_Template::GetXParency(int mtlNum, BOOL backFace)
{
	float t;
	pblock->GetValue(pb_opacity, 0, t, ivalid);
	return submtl[0] ? submtl[0]->GetXParency(mtlNum,backFace): t;
}

float LR_Template::GetShininess(int mtlNum, BOOL backFace)
{
	float sh;
	pblock->GetValue(pb_shin, 0, sh, ivalid);
	return submtl[0] ? submtl[0]->GetShininess(mtlNum,backFace): sh;
}

float LR_Template::GetShinStr(int mtlNum, BOOL backFace)
{
	return submtl[0] ? submtl[0]->GetShinStr(mtlNum,backFace): 0.0f;
}

float LR_Template::WireSize(int mtlNum, BOOL backFace)
{
	float wf;
	pblock->GetValue(pb_wiresize, 0, wf, ivalid);
	return submtl[0] ? submtl[0]->WireSize(mtlNum, backFace) : wf;
}


/*===========================================================================*\
 |	Actual shading takes place
\*===========================================================================*/

void LR_Template::Shade(ShadeContext& sc)
{
	Mtl* subMaterial = mapOn[0] ? submtl[0] : nullptr;
	if (gbufID)
		sc.SetGBufferID(gbufID);

	if(subMaterial)
		subMaterial->Shade(sc);
	// TODO: compute the color and transparency output returned in sc.out.
}

float LR_Template::EvalDisplacement(ShadeContext& sc)
{
	Mtl* subMaterial = mapOn[0] ? submtl[0] : nullptr;
	return (subMaterial) ? subMaterial->EvalDisplacement(sc) : 0.0f;
}

Interval LR_Template::DisplacementValidity(TimeValue t)
{
	Mtl* subMaterial = mapOn[0] ? submtl[0] : nullptr;

	Interval iv;
	iv.SetInfinite();
	if(subMaterial) 
		iv &= subMaterial->DisplacementValidity(t);

	return iv;
}



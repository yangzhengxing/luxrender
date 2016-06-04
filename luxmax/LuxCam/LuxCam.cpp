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

#include "LuxCam.h"

#define LuxCam_CLASS_ID	Class_ID(0x6fa5b517, 0x6caf4939)

#define XTCLUXCAM_CLASS_ID	Class_ID(0x9c3d0087, 0x85cc9f33)

#define PBLOCK_REF	0

class XTCLuxCam : public XTCObject
{
public:
	XTCLuxCam(){};
	~XTCLuxCam(){};

	Class_ID ExtensionID(){return XTCLUXCAM_CLASS_ID;}

	XTCObject *Clone(){return new XTCLuxCam();};

	void DeleteThis(){delete this;}
	int  Display(TimeValue t, INode* inode, ViewExp *vpt, int flags, Object *pObj){return 1;}

	ChannelMask DependsOn(){return GEOM_CHANNEL|TOPO_CHANNEL;}
	ChannelMask ChannelsChanged(){return GEOM_CHANNEL;}

	void PreChanChangedNotify(TimeValue t, ModContext &mc, ObjectState* os, INode *node,Modifier *mod, bool bEndOfPipeline){};
	void PostChanChangedNotify(TimeValue t, ModContext &mc, ObjectState* os, INode *node,Modifier *mod, bool bEndOfPipeline){};

	
	BOOL SuspendObjectDisplay(){return FALSE;}
	
};

class LuxCam : public Modifier 
{
public:
	//Constructor/Destructor
	LuxCam();
	virtual ~LuxCam();

	virtual void DeleteThis() { delete this; }

	// From Animatable
	virtual const TCHAR *GetObjectName() { return GetString(IDS_CLASS_NAME); }

		#pragma message(TODO("Add the channels that the modifier needs to perform its modification"))
	virtual ChannelMask ChannelsUsed()  { return EXTENSION_CHANNEL; }
	
	// We have to include the channels, that the extension object changes, so the 
	// PostChanChangedNotify will be called after the modifier added the extension objects
	// to the object flowing up the stack.

	virtual ChannelMask ChannelsChanged() { return EXTENSION_CHANNEL|GEOM_CHANNEL; }

		
	#pragma message(TODO("Return the ClassID of the object that the modifier can modify"))
	Class_ID InputType() {return defObjectClassID;}

	virtual void ModifyObject(TimeValue t, ModContext &mc, ObjectState *os, INode *node);
	//virtual void NotifyInputChanged(const Interval& changeInt, PartID partID, RefMessage message, ModContext *mc);

	virtual void NotifyPreCollapse(INode *node, IDerivedObject *derObj, int index);
	virtual void NotifyPostCollapse(INode *node,Object *obj, IDerivedObject *derObj, int index);


	virtual Interval LocalValidity(TimeValue t);

	// From BaseObject
	#pragma message(TODO("Return true if the modifier changes topology"))
	virtual BOOL ChangeTopology() {return FALSE;}
	
	virtual CreateMouseCallBack* GetCreateMouseCallBack() {return NULL;}

	virtual BOOL HasUVW();
	virtual void SetGenUVW(BOOL sw);


	virtual void BeginEditParams(IObjParam *ip, ULONG flags,Animatable *prev);
	virtual void EndEditParams(IObjParam *ip, ULONG flags,Animatable *next);


	virtual Interval GetValidity(TimeValue t);

	// Automatic texture support
	
	// Loading/Saving
	virtual IOResult Load(ILoad *iload);
	virtual IOResult Save(ISave *isave);

	//From Animatable
	virtual Class_ID ClassID() {return LuxCam_CLASS_ID;}
	virtual SClass_ID SuperClassID() { return OSM_CLASS_ID; }
	virtual void GetClassName(TSTR& s) {s = GetString(IDS_CLASS_NAME);}

	virtual RefTargetHandle Clone( RemapDir &remap );
	virtual RefResult NotifyRefChanged(const Interval& changeInt, RefTargetHandle hTarget, PartID& partID, RefMessage message, BOOL propagate);

	virtual int NumSubs() { return 1; }
	virtual TSTR SubAnimName(int /*i*/) { return GetString(IDS_PARAMS); }
	virtual Animatable* SubAnim(int /*i*/) { return pblock; }

	// TODO: Maintain the number or references here
	virtual int NumRefs() { return 1; }
	virtual RefTargetHandle GetReference(int i);

	virtual int	NumParamBlocks() { return 1; }					// return number of ParamBlocks in this instance
	virtual IParamBlock2* GetParamBlock(int /*i*/) { return pblock; } // return i'th ParamBlock
	virtual IParamBlock2* GetParamBlockByID(BlockID id) { return (pblock->ID() == id) ? pblock : NULL; } // return id'd ParamBlock

protected:
	virtual void SetReference(int , RefTargetHandle rtarg);

private:
	// Parameter block
	IParamBlock2 *pblock; //ref 0
};

void LuxCam::SetReference( int i, RefTargetHandle rtarg )
{
	if (i == PBLOCK_REF)
	{
		pblock=(IParamBlock2*)rtarg;
	}
}

RefTargetHandle LuxCam::GetReference( int i)
{
	if (i == PBLOCK_REF)
	{
		return pblock;
	}
	return nullptr;
}



class LuxCamClassDesc : public ClassDesc2 
{
public:
	virtual int IsPublic() 							{ return TRUE; }
	virtual void* Create(BOOL /*loading = FALSE*/) 		{ return new LuxCam(); }
	virtual const TCHAR *	ClassName() 			{ return GetString(IDS_CLASS_NAME); }
	virtual SClass_ID SuperClassID() 				{ return OSM_CLASS_ID; }
	virtual Class_ID ClassID() 						{ return LuxCam_CLASS_ID; }
	virtual const TCHAR* Category() 				{ return GetString(IDS_CATEGORY); }

	virtual const TCHAR* InternalName() 			{ return _T("LuxCam"); }	// returns fixed parsable name (scripter-visible name)
	virtual HINSTANCE HInstance() 					{ return hInstance; }					// returns owning module handle
	

};


ClassDesc2* GetLuxCamDesc() { 
	static LuxCamClassDesc LuxCamDesc;
	return &LuxCamDesc; 
}




enum { luxcam_params };


//TODO: Add enums for various parameters
enum { 
	pb_depthspin,
	pb_motionblurespin,
	pb_shutterspeedspin,
	pb_isospin,
	pb_fstopspin,
	pb_lensspin,
};




static ParamBlockDesc2 luxcam_param_blk ( luxcam_params, _T("params"),  0, GetLuxCamDesc(), 
	P_AUTO_CONSTRUCT + P_AUTO_UI, PBLOCK_REF, 
	//rollout
	IDD_PANEL, IDS_PARAMS, 0, 0, NULL,
	// params
	pb_depthspin, 			_T("depth spin"), 		TYPE_FLOAT, 	P_ANIMATABLE, 	IDS_DEPTHSP, 
		p_default, 		0.1f, 
		p_range, 		0.0f,1000.0f, 
		p_ui, 			TYPE_SPINNER,		EDITTYPE_FLOAT, IDC_LENSEEDIT,	IDC_LENSESPIN, 0.01f, 
		p_end,
	pb_motionblurespin, 			_T("motion blur spin"), 		TYPE_FLOAT, 	P_ANIMATABLE, 	IDS_MOTIONBLURESP, 
		p_default, 		0.1f, 
		p_range, 		0.0f,1000.0f, 
		p_ui, 			TYPE_SPINNER,		EDITTYPE_FLOAT, IDC_MOTIONBLUREDIT,	IDC_MOTIONBLURSPIN, 0.01f, 
		p_end,
	pb_shutterspeedspin, 			_T("shuter speed spin"), 		TYPE_FLOAT, 	P_ANIMATABLE, 	IDS_SHUTTERSPEEDSP, 
		p_default, 		0.1f, 
		p_range, 		0.0f,1000.0f, 
		p_ui, 			TYPE_SPINNER,		EDITTYPE_FLOAT, IDC_SHUTTERSPEEDEDIT,	IDC_SHUTTERSPEEDSPIN, 0.01f, 
		p_end,
	pb_isospin, 			_T("shuter speed spin"), 		TYPE_FLOAT, 	P_ANIMATABLE, 	IDS_ISOSP, 
		p_default, 		0.1f, 
		p_range, 		0.0f,1000.0f, 
		p_ui, 			TYPE_SPINNER,		EDITTYPE_FLOAT, IDC_ISOEDIT,	IDC_ISOSPIN, 0.01f, 
		p_end,
	pb_fstopspin, 			_T("f-stop spin"), 		TYPE_FLOAT, 	P_ANIMATABLE, 	IDS_FSTOPSP, 
		p_default, 		0.1f, 
		p_range, 		0.0f,1000.0f, 
		p_ui, 			TYPE_SPINNER,		EDITTYPE_FLOAT, IDC_FSTOPEDIT,	IDC_FSTOPSPIN, 0.01f, 
		p_end,
	pb_lensspin, 			_T("lens spin"), 		TYPE_FLOAT, 	P_ANIMATABLE, 	IDS_LENSSP, 
		p_default, 		0.1f, 
		p_range, 		0.0f,1000.0f, 
		p_ui, 			TYPE_SPINNER,		EDITTYPE_FLOAT, IDC_LENSEDIT,	IDC_LENSSPIN, 0.01f, 
		p_end,

	p_end
	);




//--- LuxCam -------------------------------------------------------
LuxCam::LuxCam()
	: pblock(nullptr)
{
	GetLuxCamDesc()->MakeAutoParamBlocks(this);
}

LuxCam::~LuxCam()
{
}

/*===========================================================================*\
 |	The validity of the parameters.  First a test for editing is performed
 |  then Start at FOREVER, and intersect with the validity of each item
\*===========================================================================*/
Interval LuxCam::LocalValidity(TimeValue /*t*/)
{
	// if being edited, return NEVER forces a cache to be built 
	// after previous modifier.
	if (TestAFlag(A_MOD_BEING_EDITED))
		return NEVER;  
	#pragma message(TODO("Return the validity interval of the modifier"))
	return NEVER;
}


/*************************************************************************************************
*
	Between NotifyPreCollapse and NotifyPostCollapse, Modify is
	called by the system.  NotifyPreCollapse can be used to save any plugin dependant data e.g.
	LocalModData
*
\*************************************************************************************************/

void LuxCam::NotifyPreCollapse(INode* /*node*/, IDerivedObject* /*derObj*/, int /*index*/)
{
	#pragma message(TODO("Perform any Pre Stack Collapse methods here"))
}



/*************************************************************************************************
*
	NotifyPostCollapse can be used to apply the modifier back onto to the stack, copying over the
	stored data from the temporary storage.  To reapply the modifier the following code can be 
	used

	Object *bo = node->GetObjectRef();
	IDerivedObject *derob = NULL;
	if(bo->SuperClassID() != GEN_DERIVOB_CLASS_ID)
	{
		derob = CreateDerivedObject(obj);
		node->SetObjectRef(derob);
	}
	else
		derob = (IDerivedObject*) bo;

	// Add ourselves to the top of the stack
	derob->AddModifier(this,NULL,derob->NumModifiers());

*
\*************************************************************************************************/

void LuxCam::NotifyPostCollapse(INode* /*node*/,Object* /*obj*/, IDerivedObject* /*derObj*/, int /*index*/)
{
	#pragma message(TODO("Perform any Post Stack collapse methods here."))

}


/*************************************************************************************************
*
	ModifyObject will do all the work in a full modifier
    This includes casting objects to their correct form, doing modifications
	changing their parameters, etc
*
\************************************************************************************************/


void LuxCam::ModifyObject(TimeValue /*t*/, ModContext& /*mc*/, ObjectState* /*os*/, INode* /*node*/) 
{
	#pragma message(TODO("Add the code for actually modifying the object"))
	/* XTCLuxCam *pObj = NULL;
	pObj = new  XTCLuxCam();
	os->obj->AddXTCObject(pObj);
	os->obj->SetChannelValidity(EXTENSION_CHAN_NUM, FOREVER);*/
}


void LuxCam::BeginEditParams( IObjParam* ip, ULONG flags, Animatable* prev )
{
	TimeValue t = ip->GetTime();
	NotifyDependents(Interval(t,t), PART_ALL, REFMSG_BEGIN_EDIT);
	NotifyDependents(Interval(t,t), PART_ALL, REFMSG_MOD_DISPLAY_ON);
	SetAFlag(A_MOD_BEING_EDITED);	

	GetLuxCamDesc()->BeginEditParams(ip, this, flags, prev);
}

void LuxCam::EndEditParams( IObjParam *ip, ULONG flags, Animatable *next)
{
	GetLuxCamDesc()->EndEditParams(ip, this, flags, next);

	TimeValue t = ip->GetTime();
	ClearAFlag(A_MOD_BEING_EDITED);
	NotifyDependents(Interval(t,t), PART_ALL, REFMSG_END_EDIT);
	NotifyDependents(Interval(t,t), PART_ALL, REFMSG_MOD_DISPLAY_OFF);
}



Interval LuxCam::GetValidity(TimeValue /*t*/)
{
	Interval valid = FOREVER;
	#pragma message(TODO("Return the validity interval of the modifier"))
	return valid;
}




RefTargetHandle LuxCam::Clone(RemapDir& remap)
{
	LuxCam* newmod = new LuxCam();
	#pragma message(TODO("Add the cloning code here"))
	newmod->ReplaceReference(PBLOCK_REF,remap.CloneRef(pblock));
	BaseClone(this, newmod, remap);
	return(newmod);
}


//From ReferenceMaker 
RefResult LuxCam::NotifyRefChanged(
		const Interval& /*changeInt*/, RefTargetHandle hTarget,
		PartID& /*partID*/,  RefMessage message, BOOL /*propagate*/) 
{
	#pragma message(TODO("Add code to handle the various reference changed messages"))
	switch (message)
	{
	case REFMSG_TARGET_DELETED:
		{
			if (hTarget == pblock)
			{
				pblock = nullptr;
			}
		}
		break;
	}
	return REF_SUCCEED;
}

/****************************************************************************************
*
 	NotifyInputChanged is called each time the input object is changed in some way
 	We can find out how it was changed by checking partID and message
*
\****************************************************************************************/

//void LuxCam::NotifyInputChanged(Interval /*changeInt*/, PartID /*partID*/, RefMessage /*message*/, ModContext* /*mc*/)
//{
//	return TRUE;
//}



//From Object
BOOL LuxCam::HasUVW() 
{ 
	#pragma message(TODO("Return whether the object has UVW coordinates or not"))
	return TRUE; 
}

void LuxCam::SetGenUVW(BOOL sw) 
{  
	if (sw==HasUVW()) 
		return;
	#pragma message(TODO("Set the plugin internal value to sw"))
}

IOResult LuxCam::Load(ILoad* /*iload*/)
{
	#pragma message(TODO("Add code to allow plugin to load its data"))
	
	return IO_OK;
}

IOResult LuxCam::Save(ISave* /*isave*/)
{
	#pragma message(TODO("Add code to allow plugin to save its data"))
	
	return IO_OK;
}


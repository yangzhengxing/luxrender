dxshadermanager.SetVisible false
mental_ray_Preferences.mrExtensionsActive = false

plugin material LRI_Light name:"LRI Light Emission" classID:#(0x32d61a4e, 0x6a3107d8) extends:Standard replaceUI:true version:1
(
	parameters main rollout:params
	(
		diffuseColor type:#color default:[255,255,255] ui:mdiffuseColor
		on diffuseColor set val do delegate.diffuse_color = val
	)
	
	rollout params "Parameters" width:160 height:227
	(
		group "Shader parameters"
		(
			colorpicker mdiffuseColor "" align:#left width:80 height:16
		)
	)
)
		
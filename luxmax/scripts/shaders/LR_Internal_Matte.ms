dxshadermanager.SetVisible false
mental_ray_Preferences.mrExtensionsActive = false

plugin material LRI_Matte name:"LRI Matte" classID:#(334255,416532) extends:Standard replaceUI:true version:1
(
	parameters main rollout:params
	(
		diffuseColor type:#color default:[150,150,150] ui:mdiffuseColor
		texunit1 type:#textureMap ui:btn_texunit1
		texunit1FilePath type:#string
		texunit1FileName type:#string
		texWidth type:#integer
		texHeight type:#integer
		
		on texunit1 set val do
		(
			delegate.diffusemap = val
			if (val != undefined)then
			(
				bitmapinfo = getbitmapinfo val.filename
				print bitmapinfo
				tmpPath = val.filename
				r = tmpPath.count
				for i = 1 to r do
				(
					if tmpPath[i] == "\\" then
					(
					 tmpPath = replace tmpPath i 1 "//"
					)
				)
				texunit1FilePath = tmpPath
				texunit1FileName = getFilenameFile val.filename
				bitmapinfo = val[3]
				bitmapinfo = val[4]
				
			)else
			(
				texunit1FilePath = ""
				texunit1FileName = ""
			)
		)
		on diffuseColor set val do delegate.diffuse_color = val
	)
	
	rollout params "Parameters" width:160 height:227
	(
		group "Shader parameters"
		(
			colorpicker mdiffuseColor "" align:#left width:80 height:16
		)
		group "Textures"
		(
			mapButton btn_texunit1 ""  width:150 height:16 across:1
		)
	)
)
		
TgBuild.Include('Tangara.CSharp') -- include tgbuild module
local simdjson_target = require('simdjson/tgbuild.lua')
my_target = TangaraCSharp.CreateFrom('Source/MyProject.csproj')
my_target:Link(simdjson_target)
-- **How 'Link' function is working**
-- First, it builds 'simdjson_target' as library and export Tangara reflection data `.tgdata`
-- Next, it generates bindings of 'simdjson_target' for 'my_target' language based on `tgdata`
-- And finally it links generated project to our target

function my_target:BeautyLinkLib(lib_target)
    lib_target:Build()
    local tgdata = lib_target:GetTgData()
    -- string parameter used to mark output folder
    -- `true` parameter used to make code setup to C# coding conventions
    -- returns target of generated bindings
    local bindings = TangaraCSharp.GenerateBindings(tgdata, 'Source/' .. lib_target.name, true)
    self:LinkTarget(bindings)
end

-- my_target:BeautyLinkLib(simdjson_target)

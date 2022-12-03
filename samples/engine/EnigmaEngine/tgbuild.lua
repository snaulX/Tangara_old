TgBuild.Include('Tangara.CMake')

EnigmaEngine_target = TangaraCMake.CreateFrom('./')

EnigmaEngine_mtgame = {}
function EnigmaEngine_mtgame:Assets(assets_dir)
    -- do something
end

EnigmaEngine = AlphaEngine:CreateEngine(EnigmaEngine_target)
EngimaEngine.mt_game = EnigmaEngine_mtgame -- additional metatable for game built on Enigma Engine
-- AlphaEngine:CreateSystem('EngimaEngine.RenderSystem', EnigmaEngine_target)

return EnigmaEngine
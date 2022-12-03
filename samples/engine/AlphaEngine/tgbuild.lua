TgBuild.Include('Tangara.CSharp')

AlphaEngine = {
    target = TangaraCSharp.CreateAOT('Source/AlphaEngine.csproj')
}

AE_Engine = {
}

AE_Game = {
}

function AlphaEngine:CreateEngine(target)
    target:Link(self.target)
    newEngine = {name = target.name, target = target}
    return setmetatable(newEngine, AE_Engine)
end

function AlphaEngine:CreateSystem(name, target)

end

function AlphaEngine.CreateGame(name)
    newGame = {name = name, scripts = {}, engine, systems = {}}
    return setmetatable(newGame, AE_Game)
end

local function GetEngine(name)
    return require('Engines/' .. name .. '/tgbuild.lua')
end

function AE_Game:UseEngine(engine_name)
    local engine = GetEngine(engine_name)
    if engine.mt_game then setmetatable(self, engine.mt_game) end
    self.engine = engine
end

function AE_Game:Build()
    for i = 1, #self.scripts do
        self.scripts[i]:Build()
    end
end

-- Build executable with embed systems
function AE_Game:BuildEmbed()
    --
end

return AlphaEngine
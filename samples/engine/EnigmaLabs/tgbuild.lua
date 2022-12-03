TgBuild.Include('Tangara.CSharp')

local EnigmaLabs_target = TangaraCSharp.CreateAOT('Source/EnigmaLabs.csproj')

EnigmaLabs = AlphaEngine.CreateGame('Enigma Labs')
EnigmaLabs:UseEngine('EnigmaEngine')
EnigmaLabs:AddScript(EnigmaLabs_target)
EnigmaLabs:Build()


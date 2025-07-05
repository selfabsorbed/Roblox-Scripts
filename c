local Players = game:GetService("Players")
local ReplicatedStorage = game:GetService("ReplicatedStorage")
local Stats = game:GetService("Stats")
local TeleportService = game:GetService("TeleportService")

local LocalPlayer = Players.LocalPlayer

local function Delay()
    task.wait((Stats.PerformanceStats.Ping:GetValue() / 2000) + .25)
end

if game.PlaceId == 6764533218 then
    queue_on_teleport(game:HttpGet("https://raw.githubusercontent.com/selfabsorbed/Roblox-Scripts/refs/heads/main/c"))
    if not LocalPlayer:WaitForChild("HatchInfo"):WaitForChild("isParticipating").Value then
        TeleportService:Teleport(98209635344835)
    end
    
    for _, Zone in workspace.THE_HATCH.Zones:GetChildren() do
        repeat
            pcall(function()
                LocalPlayer.Character.PrimaryPart.CFrame = Zone.CFrame
            end)
            Delay()
        until LocalPlayer:WaitForChild("plrStats"):WaitForChild("TempData"):WaitForChild("TheHatch2025"):WaitForChild(Zone.Name).Value
    end

    ReplicatedStorage:WaitForChild("_TheHatch"):WaitForChild("Remotes"):WaitForChild("Despawn").OnClientEvent:Once(function()
        TeleportService:Teleport(11170059897)
    end)

    ReplicatedStorage:WaitForChild("_TheHatch"):WaitForChild("Remotes"):WaitForChild("Spawn").OnClientEvent:Once(function(Name)
        repeat
            pcall(function()
                LocalPlayer.Character.PrimaryPart.CFrame = workspace:WaitForChild(Name).CFrame
            end)
            Delay()
            ReplicatedStorage:WaitForChild("_TheHatch"):WaitForChild("Remotes"):WaitForChild("Pickup"):InvokeServer()
        until LocalPlayer:WaitForChild("plrStats"):WaitForChild("TempData"):WaitForChild("TheHatch2025"):WaitForChild("RewardsGiven").Value
    end)

    ReplicatedStorage:WaitForChild("MiscRemotes"):WaitForChild("THE_HATCH"):FireServer("SpawnEgg")

elseif game.PlaceId == 11170059897 then
    queue_on_teleport(game:HttpGet("https://raw.githubusercontent.com/selfabsorbed/Roblox-Scripts/refs/heads/main/c"))

elseif game.PlaceId == 98209635344835 then
    queue_on_teleport(game:HttpGet("https://raw.githubusercontent.com/selfabsorbed/Roblox-Scripts/refs/heads/main/c"))
    ReplicatedStorage:WaitForChild("TeleportRequest"):InvokeServer(2563713593)

end

queue_on_teleport(game:HttpGet("https://raw.githubusercontent.com/selfabsorbed/Roblox-Scripts/refs/heads/main/c"))
game:GetService("TeleportService"):Teleport(98209635344835)

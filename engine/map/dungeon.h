#pragma once

#include "vec.h"
#include "room.h"
#include "tile.h"
#include "grid.h"
#include "door.h"
#include "animatedsprite.h"
#include "fog.h"
#include "pathfinding.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>


class Dungeon {
public:
    Dungeon() = default;
    Dungeon(const Grid<Tile>& tiles, const std::vector<Room>& rooms,
            const std::unordered_map<Vec, Door>& doors,
            const std::unordered_map<Vec, AnimatedSprite>& doodads,
            const std::unordered_set<Vec>& torch_positions);

    // return the position of an unoccupied tile
    Vec random_open_room_tile() const;

    // update tile sprites or conditions
    void update();

    // recompute fog of war
    void update_visibility(const Vec& position);

    void remove_actor(const Vec& position);

    // return all neighboring tile positions that are within bounds
    std::vector<Vec> neighbors(const Vec& position) const;

    // returns if tile at position blocks line of sight
    bool is_blocking(const Vec& position) const;

    // compute the set of tiles that can be seen from position
    std::unordered_set<Vec> calculate_fov(const Vec& position) const;

    // computes a series of open tiles from start to stop
    Path calculate_path(const Vec& start, const Vec& stop) const;

    // individual tiles can be access using integers x and y: Tile& tile = tiles(x, y)
    // OR
    // Vec position{x, y}; Tile& tile = tiles(position)
    Grid<Tile> tiles;

    // other elements of the dungeon
    std::vector<Room> rooms;
    std::unordered_map<Vec, Door> doors;
    std::unordered_map<Vec, AnimatedSprite> doodads; // decorations on tiles (e.g. torches)
    std::unordered_set<Vec> torch_positions;
    Fog fog; // used for computing which tiles are visible for hero
};

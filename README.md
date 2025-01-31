# cub3D - Development Guidelines

## Table of Contents
- [Task Breakdown](#task-breakdown)
- [Git Workflow](#git-workflow)
- [Code Guidelines](#code-guidelines)
- [Progress Tracking](#progress-tracking)

## Task Breakdown

### 1. Map Parsing Module
- [x] Check file extension (.cub)
  - [ ] Check file extension (.cub)
  - [ ] Handle file opening errors
- [ ] Parse map elements
  - [ ] Read and validate textures (NO, SO, WE, EA)
  - [ ] Parse colors (F, C)
  - [ ] Extract map data
- [ ] Map validation
  - [ ] Check map is surrounded by walls
  - [ ] Validate player position (N,S,E,W)
  - [ ] Ensure map has exactly one player
  - [ ] Check for invalid characters

### 2. Raycasting Module
- [ ] Basic raycasting setup
  - [ ] Implement DDA algorithm
  - [ ] Calculate ray directions
  - [ ] Handle wall collisions
- [ ] Wall rendering
  - [ ] Calculate wall heights
  - [ ] Implement distance calculations
  - [ ] Handle fish-eye effect
- [ ] Texture mapping
  - [ ] Load wall textures
  - [ ] Calculate texture coordinates
  - [ ] Apply textures to walls

### 3. Player Movement
- [ ] Basic movement
  - [ ] Forward/backward (W/S keys)
  - [ ] Left/right strafing (A/D keys)
- [ ] Rotation
  - [ ] Left/right rotation (←/→ keys)
  - [ ] Smooth movement
- [ ] Collision detection
  - [ ] Wall collision handling
  - [ ] Movement restrictions

### 4. Optimization & Polish
- [ ] Performance optimization
  - [ ] Efficient rendering
  - [ ] Memory management
- [ ] Error handling
  - [ ] Graceful error messages
  - [ ] Memory leak prevention
- [ ] Code cleanup
  - [ ] Remove debug code
  - [ ] Norminette compliance

## Git Workflow

### Branch Structure
```
main
└── feature/map-parser
└── feature/raycasting
└── feature/player-movement
```

### Commit Guidelines

#### Commit Message Format
```
[Module]: Action in present tense

- Detailed explanation of changes
- Reason for changes (if needed)
```

#### Examples of Good Commits
```
[Parser]: Add texture path validation

- Add checks for file existence
- Validate file extensions
- Handle malloc errors in path storage
```

```
[Movement]: Implement smooth player rotation

- Add rotation speed variable
- Fix jerky movement when holding key
- Update rotation matrix calculations
```

#### Bad Commit Examples (Avoid these)
```
fix stuff
updating code
WIP
```

### Pull Request Process
1. Create feature branch
2. Make commits following format above
3. Test thoroughly
4. Push and create PR
5. Request review from teammate
6. Address feedback
7. Merge when approved

## Code Guidelines

### Function Structure
```c
/*
** @brief Calculate the distance to wall hit by ray
** @param ray_dir The direction vector of the ray
** @param map_pos Current position in map grid
** @return Distance to wall hit point
*/
double  calculate_wall_distance(t_vector ray_dir, t_point map_pos)
{
    // Function implementation
}
```

### Variable Naming
```c
// Good examples
t_player    player;
int         wall_height;
double      delta_distance;

// Bad examples
int a;
double temp;
t_player p;
```

## Progress Tracking

### Daily Updates Format
```
Date: YYYY-MM-DD

Completed:
- List completed tasks
- Be specific

Working on:
- Current tasks
- Blocked tasks

Plans:
- Next tasks to tackle
- Upcoming milestones
```

### Weekly Review Checklist
- [ ] Code review session
- [ ] Update task status
- [ ] Test new features
- [ ] Check for memory leaks
- [ ] Plan next week's tasks

## Project Phases

### Phase 1: Setup and Basic Structure (Week 1)
- Repository setup
- Basic project structure
- File parsing foundation

### Phase 2: Core Mechanics (Week 2-3)
- Raycasting implementation
- Basic rendering
- Player movement

### Phase 3: Polish and Optimization (Week 4)
- Texture implementation
- Performance optimization
- Bug fixes

### Phase 4: Testing and Submission (Final Week)
- Thorough testing
- Memory leak checks
- Code cleanup
- Final documentation

## Testing Guidelines

### Regular Testing
- Run with valgrind
- Test with different maps
- Check error cases

### Map Test Cases
```
# Valid cases
valid_basic.cub        - Minimal valid map
valid_complex.cub      - Larger map with all features

# Invalid cases
invalid_walls.cub      - Map not enclosed
invalid_player.cub     - Multiple/missing player
invalid_chars.cub      - Invalid characters
```

## Resources and Tools

### Required
- Norminette
- Valgrind
- GDB/LLDB

### Recommended VSCode Extensions
- C/C++
- Norminette
- GitLens

Remember to update this README as the project evolves. Regular communication and following these guidelines will help maintain code quality and project organization.

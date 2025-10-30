#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
NC='\033[0m'

PASSED=0
FAILED=0
LEAK_TESTS=0
LEAK_FREE=0

mkdir -p maps/tests

# ========== MAPS VALIDES ==========

cat > maps/tests/valid_small.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
10N001
111111
EOF

cat > maps/tests/valid_large.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 0,0,0
C 255,255,255

11111111111
10000000001
10000N00001
10000000001
11111111111
EOF

cat > maps/tests/valid_spaces.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 50,50,50
C 200,200,200

  1111
  1001
111N01
100001
111111
EOF

cat > maps/tests/valid_complex.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 128,64,32
C 135,206,235

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
EOF

# ========== ERREURS DE PARSING ==========

cat > maps/tests/no_player.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
100001
111111
EOF

cat > maps/tests/two_players.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
10N001
10S001
111111
EOF

cat > maps/tests/three_players.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
10N0E1
10W001
111111
EOF

cat > maps/tests/open_top.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111011
100001
10N001
111111
EOF

cat > maps/tests/open_bottom.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
10N001
111011
EOF

cat > maps/tests/open_left.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
000001
10N001
111111
EOF

cat > maps/tests/open_right.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100000
10N001
111111
EOF

cat > maps/tests/space_hole.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
10 001
10N001
111111
EOF

cat > maps/tests/missing_north.cub << 'EOF'
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
10N001
111111
EOF

cat > maps/tests/missing_floor.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
C 225,30,0

111111
100001
10N001
111111
EOF

cat > maps/tests/missing_ceiling.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0

111111
100001
10N001
111111
EOF

cat > maps/tests/duplicate_texture.cub << 'EOF'
NO ./textures/north.xpm
NO ./textures/north2.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
10N001
111111
EOF

cat > maps/tests/color_overflow.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 300,100,0
C 225,30,0

111111
100001
10N001
111111
EOF

cat > maps/tests/color_negative.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F -10,100,0
C 225,30,0

111111
100001
10N001
111111
EOF

cat > maps/tests/invalid_char.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100X01
10N001
111111
EOF

cat > maps/tests/empty_map.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0
EOF

cat > maps/tests/wrong_ext.txt << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
10N001
111111
EOF

cat > maps/tests/no_extension << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
10N001
111111
EOF

# ========== EDGE CASES ==========

cat > maps/tests/empty_line_in_map.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001

10N001
111111
EOF

cat > maps/tests/only_spaces.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0


EOF

cat > maps/tests/color_with_spaces.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220, 100, 0
C 225,30,0

111111
100001
10N001
111111
EOF

cat > maps/tests/duplicate_color.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
F 220,100,0
C 225,30,0

111111
100001
10N001
111111
EOF

cat > maps/tests/diagonal_hole.cub << 'EOF'
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

11111
1   1
1 N 1
1   1
11111
EOF

test_map() {
    local test_name="$1"
    local map_file="$2"
    local should_pass="$3"

    printf "%-40s" "$test_name"

    output=$(./cub3D "$map_file" 2>&1)
    exit_code=$?

    if [ "$should_pass" = "true" ]; then
        if [ $exit_code -eq 0 ]; then
            echo -e "${GREEN}✓ PASS${NC}"
            ((PASSED++))
        else
            echo -e "${RED}✗ FAIL${NC} (Expected SUCCESS, got: $output)"
            ((FAILED++))
        fi
    else
        if [ $exit_code -ne 0 ]; then
            echo -e "${GREEN}✓ PASS${NC}"
            ((PASSED++))
        else
            echo -e "${RED}✗ FAIL${NC} (Expected ERROR, got SUCCESS)"
            ((FAILED++))
        fi
    fi
}

test_leaks() {
    local test_name="$1"
    local map_file="$2"

    printf "%-40s" "$test_name"
    ((LEAK_TESTS++))

    valgrind_output=$(valgrind --leak-check=full --error-exitcode=42 --quiet ./cub3D "$map_file" 2>&1)
    exit_code=$?

    if echo "$valgrind_output" | grep -q "All heap blocks were freed"; then
        echo -e "${GREEN}✓ NO LEAKS${NC}"
        ((LEAK_FREE++))
    elif echo "$valgrind_output" | grep -q "definitely lost"; then
        leaked=$(echo "$valgrind_output" | grep "definitely lost" | awk '{print $4}')
        echo -e "${RED}✗ LEAK: $leaked bytes${NC}"
    elif echo "$valgrind_output" | grep -q "still reachable"; then
        reachable=$(echo "$valgrind_output" | grep "still reachable" | awk '{print $4}')
        echo -e "${YELLOW}⚠ REACHABLE: $reachable bytes${NC}"
        ((LEAK_FREE++))
    else
        echo -e "${GREEN}✓ NO LEAKS${NC}"
        ((LEAK_FREE++))
    fi
}

echo -e "${BLUE}=========================================="
echo "        CUB3D PARSER - FULL TESTS"
echo -e "==========================================${NC}"
echo ""

make -s

echo -e "${YELLOW}--- VALID MAPS (Should PASS) ---${NC}"
test_map "Small valid map" "maps/tests/valid_small.cub" "true"
test_map "Large valid map" "maps/tests/valid_large.cub" "true"
test_map "Map with spaces" "maps/tests/valid_spaces.cub" "true"
test_map "Complex map" "maps/tests/valid_complex.cub" "true"

echo ""
echo -e "${YELLOW}--- PLAYER ERRORS (Should FAIL) ---${NC}"
test_map "No player" "maps/tests/no_player.cub" "false"
test_map "Two players" "maps/tests/two_players.cub" "false"
test_map "Three players" "maps/tests/three_players.cub" "false"

echo ""
echo -e "${YELLOW}--- MAP NOT CLOSED (Should FAIL) ---${NC}"
test_map "Open top" "maps/tests/open_top.cub" "false"
test_map "Open bottom" "maps/tests/open_bottom.cub" "false"
test_map "Open left" "maps/tests/open_left.cub" "false"
test_map "Open right" "maps/tests/open_right.cub" "false"
test_map "Space hole in map" "maps/tests/space_hole.cub" "false"

echo ""
echo -e "${YELLOW}--- MISSING ELEMENTS (Should FAIL) ---${NC}"
test_map "Missing north texture" "maps/tests/missing_north.cub" "false"
test_map "Missing floor color" "maps/tests/missing_floor.cub" "false"
test_map "Missing ceiling color" "maps/tests/missing_ceiling.cub" "false"

echo ""
echo -e "${YELLOW}--- INVALID ELEMENTS (Should FAIL) ---${NC}"
test_map "Duplicate texture" "maps/tests/duplicate_texture.cub" "false"
test_map "Color overflow (>255)" "maps/tests/color_overflow.cub" "false"
test_map "Negative color" "maps/tests/color_negative.cub" "false"
test_map "Invalid character in map" "maps/tests/invalid_char.cub" "false"
test_map "Empty map" "maps/tests/empty_map.cub" "false"

echo ""
echo -e "${YELLOW}--- EDGE CASES (Should FAIL) ---${NC}"
test_map "Empty line in map" "maps/tests/empty_line_in_map.cub" "false"
test_map "Only spaces" "maps/tests/only_spaces.cub" "false"
test_map "Color with spaces" "maps/tests/color_with_spaces.cub" "false"
test_map "Duplicate color" "maps/tests/duplicate_color.cub" "false"
test_map "Diagonal hole" "maps/tests/diagonal_hole.cub" "false"

echo ""
echo -e "${YELLOW}--- FILE ERRORS (Should FAIL) ---${NC}"
test_map "Wrong extension (.txt)" "maps/tests/wrong_ext.txt" "false"
test_map "No extension" "maps/tests/no_extension" "false"
test_map "No arguments" "" "false"
test_map "File doesn't exist" "maps/tests/nonexistent.cub" "false"

echo ""
echo -e "${MAGENTA}=========================================="
echo "          VALGRIND MEMORY TESTS"
echo -e "==========================================${NC}"
echo ""

echo -e "${YELLOW}--- VALID MAPS (No Leaks Expected) ---${NC}"
test_leaks "Valid small" "maps/tests/valid_small.cub"
test_leaks "Valid large" "maps/tests/valid_large.cub"
test_leaks "Valid with spaces" "maps/tests/valid_spaces.cub"

echo ""
echo -e "${YELLOW}--- ERROR MAPS (No Leaks Expected) ---${NC}"
test_leaks "No player" "maps/tests/no_player.cub"
test_leaks "Two players" "maps/tests/two_players.cub"
test_leaks "Open map" "maps/tests/open_top.cub"
test_leaks "Missing texture" "maps/tests/missing_north.cub"
test_leaks "Invalid color" "maps/tests/color_overflow.cub"
test_leaks "Wrong extension" "maps/tests/wrong_ext.txt"

echo ""
echo -e "${BLUE}=========================================="
echo -e "  PARSER TESTS: $((PASSED + FAILED)) tests"
echo -e "  ${GREEN}PASSED: $PASSED${NC}"
echo -e "  ${RED}FAILED: $FAILED${NC}"
echo ""
echo -e "  MEMORY TESTS: $LEAK_TESTS tests"
echo -e "  ${GREEN}LEAK-FREE: $LEAK_FREE${NC}"
echo -e "  ${RED}LEAKING: $((LEAK_TESTS - LEAK_FREE))${NC}"
echo -e "==========================================${NC}"

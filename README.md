#Chamber-Crawler 3000
Final Object Oriented Programming project made for University of Waterloo. Developed by Austin Luo and Yi Chen. Do not use this code in your own CS246 project

###How to run
1. 'git clone https://github.com/aluo123/Chamber-Crawler-3000' into a local directory
2. 'make' to compile the code for linux environment
3. Run with './cc3k' with no arguments for random generated levels. Run './cc3k cc3kfloor.txt' to run with pre-generated levels

###Select a Class
|:-:|:-:|:-:|:-:|:-:|
|Race | HP | Attack | Defense | Special Effects |
|:---|:---:|:---:|:---:|:---|
|Shade | 125 | 25 | 25 | None|
|Drow | 150 | 25 | 15 | Potions are 1.5 times as effective|
|Vampire | 50 | 25 | 25 | Gains 5 hp per attack, no max health |
|Troll | 120 | 25 | 15 | Heals 5 hp per turn |
|Goblin | 110 | 15 | 20 | Loots 5 gold from every slain enemy |

###How to play
1. To move, type 'no' to move one space north, 'ne' for one space north-east, 'ea' for one space east, 'se' for one space south-east, 'so' for one space south, 'sw' for one space south-west, 'we' for one space west, and 'nw' for one space north-west
2. To attack, type 'a dir' where 'dir' is one of the 8 directions
3. To use a potion, type 'u dir' where 'dir' is one of the 8 directions
4. Walk over gold to pick up gold

###Types of Enemies
|Race | HP | Attack | Defense | Special Effects | Drops |
|---|:---:|:---:|:---:|:---|:---:|
|Human|140|20|20|None|4 Gold|
|Dwarf|100|20|30|Vampires lose 5hp when attacking|1 or 2 Gold|
|Elf|140|30|20|Attacks twice, unless you are a Drow|1 or 2 Gold|
|Orc|180|30|25|Deals 50% more damage to Goblins|1 or 2 gold|
|Merchant|30|70|5|Neutral unless a merchant had been attacked before|4 Gold|
|Dragon|150|20|20|Stationary around it's hoard|None - but you can pick up it's hoard|
|Halfling|100|15|20|50% chance to miss|1 or 2 gold|

###Goal
The goal of the game is to try and get as much gold as possible. The game ends when you complete the 5th level or die.

###Legend
|Symbol|Description|
|:------:|-----------|
| . | Tile |
| + | Door |
| \| | Wall |
| # | Passage |
| @ | Player |
| P | Potion |
| G | Gold |
| \ | Staircase |
| H | Enemy - Human |
| E | Enemy - Elf |
| W | Enemy - Dwarf |
| L | Enemy - Halfling |
| O | Enemy - Orc |
| D | Enemy - Dragon |
| M | Enemy - Merchant |

<h1 align="center">PIPEX</h1>

## Index

- [Index](#index)
- [Description :clipboard:](#description-clipboard)
- [Usage](#usage)
- [Operation :wrench:](#operation-wrench)
- [Learnings :brain:](#learnings-brain)
- [Author](#author)

## Description :clipboard:
<p>

so_long is a 2D game.

For more information about the project check the [subject here](https://github.com/pedromessetti/so_long/blob/master/subject.pdf). The program was written following the rules described in the 42 Norme. To check the Norme [click here](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf).
</p>

## Usage
<p>

Clone the repository and `cd` in the project folder.

Type `make` on the command line. 

To run the game type in the command line: 

`./so_long <path/to/map.ber>`

</p>

## Operation :wrench:

<p>

The program first checks the number of arguments passed, then reads the game map from a file using the `read_map()` function. This function parses the file and stores the game map in a `t_game` struct.

After reading the game map, the function checks for errors using the `check_errors()` function. This function checks if the game map is valid, if it's not, exits the program with an map error message.

Then the program initializes the game window using the `mlx_init()` and `mlx_new_window()` functions from the MiniLibX library. These functions create a new window with the specified width and height. After the window is opened the game loads the images into memory, and stores them in the `t_game` struct to free then before exiting the program.

To set up event handlers the program uses `mlx_key_hook()` and `mlx_hook()` functions from the MiniLibX library. The `mlx_key_hook()` sets up a key press event handler that calls the `control()` function to handle when a key is pressed. The `mlx_hook()` sets up a window close event handler that calls the exit_game function when the window is closed.

Finally, the program enters in the main event loop using the `mlx_loop()` function. This function waits for events such as key presses and window close events, and calls the appropriate event handlers when events occur.

</p>

## Learnings :brain:

<p>

</p>

## Author
| [<img src="https://avatars.githubusercontent.com/u/105685220?v=4" width=115><br><sub>Pedro Vinicius Messetti</sub>](https://github.com/pedromessetti) |
| :---------------------------------------------------------------------------------------------------------------------------------------------------: |
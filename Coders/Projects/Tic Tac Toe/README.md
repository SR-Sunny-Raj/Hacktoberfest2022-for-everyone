# Tic Tac Toe AI Game Development

This is a game created on Python of the famous Tic Tac Toe game. The AI wins a considerable of times. The game is a bit monotonous i.e. the AI will make the same moves for same input given. 

This is the position of the game moves user can input:
- 0 &ensp;  1 &ensp;  2     &emsp; &emsp; &emsp; &emsp;     _  &ensp; _  &ensp; _ 
- 3 &ensp;  4 &ensp;  5     &emsp; &emsp; &emsp; &emsp;    _  &ensp; _  &ensp; _ 
- 6  &ensp; 7 &ensp;  8     &emsp;  &emsp; &emsp; &emsp;   _ &ensp;  _  &ensp; _

This is the list of preferred order of moves taken by AI.
- Wins immediately
- Prevents an immediate loss
- Places AI in 1 move away from a win
- Prevents user from being a single move away from win.
- First possible move from position 0 to position 8.

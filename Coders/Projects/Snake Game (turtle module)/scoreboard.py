from turtle import Turtle


class Scoreboard(Turtle):
    def __init__(self):
        super().__init__()
        self.score = 0
        self.color("white")
        self.penup()
        self.goto(0, 270)
        self.hideturtle()
        self.update_scoreboard()

    def update_scoreboard(self):
        self.write(f"Score: {self.score}", align="center", font=("Courier", 20, "normal"))

    def game_over(self):
        self.goto(0, 0)
        self.color("red")
        self.write("Game Over", align="center", font=("Courier", 20, "normal"))

    def increase_score(self):
        self.score += 1
        self.clear()
        self.update_scoreboard()


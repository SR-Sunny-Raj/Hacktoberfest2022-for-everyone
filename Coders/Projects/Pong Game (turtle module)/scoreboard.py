from turtle import Turtle


class Scoreboard(Turtle):
    def __init__(self):
        super().__init__()
        self.color("white")
        self.penup()
        self.hideturtle()
        self.l_score = 0
        self.r_score = 0
        self.update_scoreboard()

    def update_scoreboard(self):
        self.clear()
        self.goto(-130, 220)
        self.write(self.l_score, align="center", font=("Courier", 50, "normal"))
        self.goto(130, 220)
        self.write(self.r_score, align="center", font=("Courier", 50, "normal"))

    def l_point(self):
        self.l_score += 1
        self.update_scoreboard()

    def r_point(self):
        self.r_score += 1
        self.update_scoreboard()

    def game_over(self):
        winner = ""
        if self.r_score > self.l_score:
            winner += "Right"
        else:
            winner += "Left"
        self.goto(0, 0)
        self.color("blue")
        self.write(f"Winner is {winner} player!", align="center", font=("Courier", 30, "normal"))

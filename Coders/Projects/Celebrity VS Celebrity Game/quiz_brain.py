class QuizBrain:
    def __init__(self, q_list):
        self.question_number = 0
        self.question_list = q_list
        self.score = 0

    def still_has_questions(self):
        if self.question_number < len(self.question_list):
            return True
        else:
            return False

    def next_question(self):
        current_question = self.question_list[self.question_number]
        self.question_number += 1
        user_ans = input(f"\nQ.{self.question_number}: {current_question.text}  (True/False): ")
        self.check_ans(user_ans, current_question.answer)

    def check_ans(self, user_ans, correct_ans):
        if user_ans.lower() == correct_ans.lower():
            self.score += 1
            print(f"Correct answer")

        else:
            print("wrong answer")
        print(f"the correct answer was {correct_ans}, current score: {self.score}/{self.question_number}")

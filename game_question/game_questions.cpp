#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Structure to storage the questions and the answers

struct Question {
	string text_question;
	string pick_option[3];
	int correctAnswer;
};

//Vector to storage the questions

vector<Question> questions;

//Function to add the questions

void addQuestion() {

	Question question;
	cout << "Type the text of your question: ";
	getline(cin, question.text_question);
	for (int i = 0; i < 3; i++) {
		cout << "Insert the option - " << i + 1 << " : ";
		getline(cin, question.pick_option[i]);
	}

	cout << "Which option is the correct answer? (insert the number of the option 1 - 3) : ";
	cin >> question.correctAnswer;
	cin.ignore(); // it will ignore the breakline
	questions.push_back(question);
	cout << "The question was sucessfully added!" << endl;

}

//function to play

void playGame() {

	if (questions.empty()) {
		cout << "There's no questions added to this game yet, please add a couple of questions..." << endl;
		return;
	}

	int score = 0;
	for (const auto& question : questions) {

		cout << "Question: " << question.text_question << endl;

		for (int i = 0; i < 3; i++) {
			cout << i + 1 << ". " << question.pick_option[i] << endl;
		}

		int given_answer;
		cout << "Type the number equivalent to your final answer: ";
		cin >> given_answer;
		cin.ignore();
		if (given_answer == question.correctAnswer) {

			cout << "CONGRATS!!! Your answer is CORRECT!!!" << endl;
			score++;

		}
		else {

			cout << "SO SAD... Your answer is wrong... The right answer is: " << question.pick_option[question.correctAnswer - 1] << "." << endl;
		}

		cout << endl;

	}

	cout << "You achieved a score of " << score << " from a total of " << questions.size() << "." << endl;

}

//Main function

int main() {

	while (true) {

		cout << "Menu: " << endl;
		cout << "1. Add question" << endl;
		cout << "2. Play the game" << endl;
		cout << "3. Quit the game" << endl;

		int pick_choice;
		cin >> pick_choice;
		cin.ignore();

		switch (pick_choice) {

		case 1:
			addQuestion();
			break;

		case 2:
			playGame();
			break;

		case 3:
			return 0;

		default:
			cout << "This option is not valid" << endl;
		}
	}

	return 0;

}
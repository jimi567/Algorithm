#include <bits/stdc++.h>
using namespace std;
class Stack //배열을 이용한 정적 스택
{
private:

	int top;
	int arr[10000]; //스택의 최대 크게 10000으로 지정
public:
	Stack() { //생성자
		top = -1;
	}

	void push(int data) { //data를 스택의 상단에 추가
		arr[++top] = data;
	}

	int pop() { //top을 제거 만약 스택이 비어있으면 -1 top이 pop되면 제거된 수 반환
		if (top == -1) return -1;
		else {
			return arr[top--];
		}
	}

	int size() { //스택의 크기 반환
		return top + 1;
	}

	bool isEmpty() { //비어있으면 1 아니면 0
		return (top < 0);
	}
	int peek() { //스택의 탑 반환
		if (isEmpty()) return -1; // 스택이 비어있으면 -1 반환
		else return arr[top];
	}

};

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	Stack stack;

	int loop;
	cin >> loop;
	while (loop--) {
		string oper;
		cin >> oper;
		int data;
		if (oper == "push") {
			cin >> data;
			stack.push(data);
		}
		else if (oper == "pop") {
			cout << stack.pop() << endl;
		}
		else if (oper == "size") {
			cout << stack.size() << endl;
		}
		else if (oper == "empty") {
			cout << stack.isEmpty() << endl;
		}
		else cout << stack.peek() << endl;
	}
}

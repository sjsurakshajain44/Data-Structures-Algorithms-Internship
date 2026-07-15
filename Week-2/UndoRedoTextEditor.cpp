#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor {
private:
    string text;
    stack<string> undoStack;
    stack<string> redoStack;

public:
    void write(string newText) {
        undoStack.push(text);

        while (!redoStack.empty()) {
            redoStack.pop();
        }

        text += newText;

        cout << "Current Text: " << text << endl;
    }

    void undo() {
        if (undoStack.empty()) {
            cout << "Nothing to undo.\n";
            return;
        }

        redoStack.push(text);
        text = undoStack.top();
        undoStack.pop();

        cout << "After Undo: " << text << endl;
    }

    void redo() {
        if (redoStack.empty()) {
            cout << "Nothing to redo.\n";
            return;
        }

        undoStack.push(text);
        text = redoStack.top();
        redoStack.pop();

        cout << "After Redo: " << text << endl;
    }
};

int main() {
    TextEditor editor;

    editor.write("Hello ");
    editor.write("World");

    editor.undo();
    editor.redo();

    return 0;
}

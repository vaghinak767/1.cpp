#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stack>

// Forward declarations
class Editor;
class Application;
class Command;

// Command Interface
class Command {
protected:
    Application* app; // Reference to the application
    Editor* editor;   // Reference to the editor
    std::string backup; // Backup of the editor's text

public:
    Command(Application* app, Editor* editor) : app(app), editor(editor) {}
    virtual ~Command() {}

    // Makes a backup of the editor's state
    void saveBackup() {
        backup = editor->getText();
    }

    // Restores the editor's state from the backup
    void undo() {
        editor->setText(backup);
    }

    // Executes the command
    virtual bool execute() = 0;
};

// Receiver class: Editor
class Editor {
public:
    std::string text;

    std::string getSelection() const {
        return text;  // In real use, it would return the selected text.
    }

    void deleteSelection() {
        text.clear();  // Deletes the selected text.
    }

    void replaceSelection(const std::string& newText) {
        text = newText;  // Replaces the selected text with newText.
    }

    std::string getText() const {
        return text;
    }

    void setText(const std::string& newText) {
        text = newText;
    }
};

// Concrete Command: Copy Command
class CopyCommand : public Command {
public:
    CopyCommand(Application* app, Editor* editor) : Command(app, editor) {}

    bool execute() override {
        app->clipboard = editor->getSelection();
        std::cout << "Copy: " << app->clipboard << std::endl;
        return false; // Does not change editor state
    }
};

// Concrete Command: Cut Command
class CutCommand : public Command {
public:
    CutCommand(Application* app, Editor* editor) : Command(app, editor) {}

    bool execute() override {
        saveBackup();
        app->clipboard = editor->getSelection();
        editor->deleteSelection();
        std::cout << "Cut: " << app->clipboard << std::endl;
        return true; // Changes editor state
    }
};

// Concrete Command: Paste Command
class PasteCommand : public Command {
public:
    PasteCommand(Application* app, Editor* editor) : Command(app, editor) {}

    bool execute() override {
        saveBackup();
        editor->replaceSelection(app->clipboard);
        std::cout << "Paste: " << editor->getText() << std::endl;
        return true; // Changes editor state
    }
};

// Concrete Command: Undo Command
class UndoCommand : public Command {
public:
    UndoCommand(Application* app, Editor* editor) : Command(app, editor) {}

    bool execute() override {
        app->undo();
        return false;
    }
};

// Command History (stores commands that modify the state)
class CommandHistory {
private:
    std::stack<std::unique_ptr<Command>> history;

public:
    void push(std::unique_ptr<Command> command) {
        history.push(std::move(command));
    }

    Command* pop() {
        if (history.empty()) return nullptr;
        Command* cmd = history.top().release();
        history.pop();
        return cmd;
    }
};

// Sender class: Application
class Application {
public:
    std::string clipboard;
    Editor editor;
    CommandHistory history;

    // Executes a command and checks if it needs to be added to history
    void executeCommand(std::unique_ptr<Command> command) {
        if (command->execute()) {
            history.push(std::move(command));
        }
    }

    // Undo the last command in history
    void undo() {
        Command* command = history.pop();
        if (command) {
            command->undo();
            delete command;
        }
    }
};

// Main function demonstrating the usage of the pattern
int main() {
    Application app;
    app.editor.setText("Hello, World!");  // Initial text

    // Execute Copy
    app.executeCommand(std::make_unique<CopyCommand>(&app, &app.editor));

    // Execute Cut
    app.executeCommand(std::make_unique<CutCommand>(&app, &app.editor));

    // Execute Paste
    app.executeCommand(std::make_unique<PasteCommand>(&app, &app.editor));

    // Undo the Paste
    app.executeCommand(std::make_unique<UndoCommand>(&app, &app.editor));

    return 0;
}

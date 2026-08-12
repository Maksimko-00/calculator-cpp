#include <iostream>
#include <limits>
#include <windows.h> // для SetConsoleOutputCP

int main() {
    SetConsoleOutputCP(65001); // UTF‑8 для вывода
    SetConsoleCP(65001);       // UTF‑8 для ввода (если нужно)

    double a, b;
    char op;

    std::cout << "Калькулятор (введите выражение: число оператор число)\n";
    std::cout << "Пример: 5 + 3\n";
    std::cout << "Операторы: -, +, *, /\n";

    while (true) {
        std::cout << "> ";
        if (!(std::cin >> a >> op >> b)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Попробуйте снова.\n";
            continue;
        }

        double result = 0.0;
        bool ok = true;

        switch (op) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/':
                if (b == 0) {
                    std::cout << "Ошибка: деление на ноль!\n";
                    ok = false;
                } else {
                    result = a / b;
                }
                break;
            default:
                std::cout << "Неизвестный оператор: " << op << "\n";
                ok = false;
        }

        if (ok) {
            std::cout << "Результат: " << result << "\n";
        }
    }

    return 0;
}

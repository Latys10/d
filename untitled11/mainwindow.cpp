#include "mainwindow.h"
#include "lesson.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Центральный виджет
    QWidget *central = new QWidget(this);
    setCentralWidget(central);
    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    // 1) Предмет
    QHBoxLayout *subjLayout = new QHBoxLayout();
    QLabel *subjLabel = new QLabel("Предмет:", this);
    subjectEdit = new QLineEdit(this);
    subjLayout->addWidget(subjLabel);
    subjLayout->addWidget(subjectEdit);
    mainLayout->addLayout(subjLayout);

    // 2) Преподаватель
    QHBoxLayout *teacherLayout = new QHBoxLayout();
    QLabel *teacherLabel = new QLabel("Преподаватель:", this);
    teacherEdit = new QLineEdit(this);
    teacherLayout->addWidget(teacherLabel);
    teacherLayout->addWidget(teacherEdit);
    mainLayout->addLayout(teacherLayout);

    // 3) Аудитория
    QHBoxLayout *roomLayout = new QHBoxLayout();
    QLabel *roomLabel = new QLabel("Аудитория:", this);
    classroomEdit = new QLineEdit(this);
    roomLayout->addWidget(roomLabel);
    roomLayout->addWidget(classroomEdit);
    mainLayout->addLayout(roomLayout);

    // 4) Номер в расписании
    QHBoxLayout *numLayout = new QHBoxLayout();
    QLabel *numLabel = new QLabel("Номер в расписании:", this);
    scheduleNumberEdit = new QLineEdit(this);
    numLayout->addWidget(numLabel);
    numLayout->addWidget(scheduleNumberEdit);
    mainLayout->addLayout(numLayout);

    // 5) Тип (радиокнопки)
    QHBoxLayout *typeLayout = new QHBoxLayout();
    QLabel *typeLabel = new QLabel("Тип:", this);
    lectureRadio = new QRadioButton("Лекция", this);
    practiceRadio = new QRadioButton("Практика", this);
    typeGroup = new QButtonGroup(this);
    typeGroup->addButton(lectureRadio);
    typeGroup->addButton(practiceRadio);
    typeLayout->addWidget(typeLabel);
    typeLayout->addWidget(lectureRadio);
    typeLayout->addWidget(practiceRadio);
    typeLayout->addStretch();
    mainLayout->addLayout(typeLayout);

    // 6) Ожидание (чекбоксы)
    QHBoxLayout *expectLayout = new QHBoxLayout();
    QLabel *expectLabel = new QLabel("Ожидание:", this);
    controlCheck = new QCheckBox("Контрольная", this);
    attendanceCheck = new QCheckBox("Проверка посещений", this);
    cancelCheck = new QCheckBox("Отмена", this);
    expectLayout->addWidget(expectLabel);
    expectLayout->addWidget(controlCheck);
    expectLayout->addWidget(attendanceCheck);
    expectLayout->addWidget(cancelCheck);
    expectLayout->addStretch();
    mainLayout->addLayout(expectLayout);

    // Кнопки
    QHBoxLayout *btnLayout = new QHBoxLayout();
    resetButton = new QPushButton("Сброс", this);
    resetButton->setStyleSheet("background-color: red; color: white;");
    saveButton = new QPushButton("Сохранить", this);
    saveButton->setStyleSheet("background-color: green; color: white;");
    btnLayout->addWidget(resetButton);
    btnLayout->addWidget(saveButton);
    btnLayout->addStretch();
    mainLayout->addLayout(btnLayout);

    // Связываем сигналы и слоты
    connect(resetButton, &QPushButton::clicked, this, &MainWindow::onResetClicked);
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::onSaveClicked);

    // Настройки окна
    setWindowTitle("Пара");
    setStyleSheet("background-color: white;");
    resize(400, 300);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onResetClicked()
{
    subjectEdit->clear();
    teacherEdit->clear();
    classroomEdit->clear();
    scheduleNumberEdit->clear();

    // Снимаем выбор радиокнопок
    lectureRadio->setAutoExclusive(false);
    practiceRadio->setAutoExclusive(false);
    lectureRadio->setChecked(false);
    practiceRadio->setChecked(false);
    lectureRadio->setAutoExclusive(true);
    practiceRadio->setAutoExclusive(true);

    // Снимаем все чекбоксы
    controlCheck->setChecked(false);
    attendanceCheck->setChecked(false);
    cancelCheck->setChecked(false);
}

void MainWindow::onSaveClicked()
{
    // Получаем данные (обрезаем пробелы)
    QString subject = subjectEdit->text().trimmed();
    QString teacher = teacherEdit->text().trimmed();
    QString classroom = classroomEdit->text().trimmed();
    QString scheduleNumber = scheduleNumberEdit->text().trimmed();

    // Проверка обязательных полей
    if (subject.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Поле 'Предмет' не может быть пустым.");
        return;
    }
    if (teacher.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Поле 'Преподаватель' не может быть пустым.");
        return;
    }
    if (classroom.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Поле 'Аудитория' не может быть пустым.");
        return;
    }
    if (scheduleNumber.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Поле 'Номер в расписании' не может быть пустым.");
        return;
    }

    // Проверка типа
    if (!lectureRadio->isChecked() && !practiceRadio->isChecked()) {
        QMessageBox::warning(this, "Ошибка", "Выберите тип пары (Лекция или Практика).");
        return;
    }
    QString type = lectureRadio->isChecked() ? "Лекция" : "Практика";

    // ---- Валидация с помощью регулярных выражений (упрощённые шаблоны) ----
    // 1) Предмет: только русские буквы, каждое слово с заглавной
    QRegularExpression subjectRx("^[А-Я][а-я]*(\\s[А-Я][а-я]*)*$");
    if (!subjectRx.match(subject).hasMatch()) {
        QMessageBox::warning(this, "Ошибка",
                             "Предмет должен содержать только русские буквы, каждое слово начинается с заглавной.");
        return;
    }

    // 2) Преподаватель: Фамилия И. (или И. О.) – только русские буквы и точки
    //    Шаблон: одна заглавная, затем строчные, пробел, заглавная буква и точка,
    //    затем опционально пробел и ещё одна заглавная с точкой.
    QRegularExpression teacherRx("^[А-Я][а-я]+\\s[А-Я]\\.(?:\\s[А-Я]\\.)?$");
    if (!teacherRx.match(teacher).hasMatch()) {
        QMessageBox::warning(this, "Ошибка",
                             "Преподаватель должен быть в формате: Фамилия И. (или И. О.), например 'Иванов И. И.'");
        return;
    }

    // 3) Аудитория: число 101-140,201-240,301-340,401-440 и опционально буква А
    QRegularExpression classroomRx("^(10[1-9]|1[1-3][0-9]|140|20[1-9]|2[1-3][0-9]|240|30[1-9]|3[1-3][0-9]|340|40[1-9]|4[1-3][0-9]|440)(А)?$");
    if (!classroomRx.match(classroom).hasMatch()) {
        QMessageBox::warning(this, "Ошибка",
                             "Аудитория должна быть числом из диапазонов 101-140, 201-240, 301-340, 401-440, возможно с буквой А в конце.");
        return;
    }

    // 4) Номер в расписании: цифра от 1 до 8
    QRegularExpression scheduleRx("^[1-8]$");
    if (!scheduleRx.match(scheduleNumber).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Номер в расписании должен быть от 1 до 8.");
        return;
    }

    // Собираем ожидания
    QStringList expectations;
    if (controlCheck->isChecked()) expectations << "Контрольная";
    if (attendanceCheck->isChecked()) expectations << "Проверка посещений";
    if (cancelCheck->isChecked()) expectations << "Отмена";
    QString expectationsStr = expectations.join(", ");

    // Создаём объект и сохраняем
    Lesson lesson(subject, teacher, classroom, scheduleNumber, type, expectationsStr);
    if (lesson.saveToFile("result.txt")) {
        QMessageBox::information(this, "Успех", "Данные сохранены в result.txt");
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось сохранить файл.");
    }
}

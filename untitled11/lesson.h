#ifndef LESSON_H
#define LESSON_H

#include <QString>

class Lesson
{
public:
    // Конструктор принимает все данные
    Lesson(const QString &subject, const QString &teacher, const QString &classroom,
           const QString &scheduleNumber, const QString &type, const QString &expectations);

    // Сохранение в файл
    bool saveToFile(const QString &filename) const;

private:
    QString m_subject;
    QString m_teacher;
    QString m_classroom;
    QString m_scheduleNumber;
    QString m_type;
    QString m_expectations;
};

#endif // LESSON_H


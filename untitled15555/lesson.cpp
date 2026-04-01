#include "lesson.h"
#include <QFile>
#include <QTextStream>

Lesson::Lesson(const QString &subject, const QString &teacher, const QString &classroom,
               const QString &scheduleNumber, const QString &type, const QString &expectations)
    : m_subject(subject), m_teacher(teacher), m_classroom(classroom),
    m_scheduleNumber(scheduleNumber), m_type(type), m_expectations(expectations)
{
}
bool Lesson::saveToFile(const QString &filename) const
{
    QFile file(filename);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        return false;
    }
    QTextStream out(&file);
    out << m_subject << "," << m_teacher << "," << m_classroom << ","
        << m_scheduleNumber << "," << m_type << "," << m_expectations << "\n";
    file.close();
    return true;
}

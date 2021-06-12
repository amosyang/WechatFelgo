#ifndef CHATSCONTROLLER_H
#define CHATSCONTROLLER_H

#include <QObject>

class ChatItem : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QString avatar READ avatar WRITE setAvatar NOTIFY avatarChanged)
  Q_PROPERTY(
    QString groupName READ groupName WRITE setGroupName NOTIFY groupNameChanged)
  Q_PROPERTY(
    QString message READ message WRITE setMessage NOTIFY messageChanged)
  Q_PROPERTY(qint64 date READ date WRITE setDate NOTIFY dateChanged)
  Q_PROPERTY(bool isMute READ isMute WRITE setIsMute NOTIFY isMuteChanged)
  Q_PROPERTY(int unreadCount READ unreadCount WRITE setUnreadCount NOTIFY
               unreadCountChanged)
public:
  ChatItem(const QString& avatar,
           const QString& groupName,
           const QString& message,
           qint64 date,
           bool isMute,
           int unreadCount)
    : m_avatar(avatar)
    , m_groupName(groupName)
    , m_message(message)
    , m_date(date)
    , m_isMute(isMute)
    , m_unreadCount(unreadCount)
  {}

  QString avatar() const { return m_avatar; }
  void setAvatar(const QString& avatar)
  {
    m_avatar = avatar;
    emit avatarChanged();
  }

  QString groupName() const { return m_groupName; }
  void setGroupName(const QString& groupName)
  {
    m_groupName = groupName;
    emit groupNameChanged();
  }

  QString message() const { return m_message; }
  void setMessage(const QString& message)
  {
    m_message = message;
    emit messageChanged();
  }

  qint64 date() const { return m_date; }
  void setDate(qint64 date)
  {
    m_date = date;
    emit dateChanged();
  }

  qint64 isMute() const { return m_isMute; }
  void setIsMute(qint64 isMute)
  {
    m_isMute = isMute;
    emit isMuteChanged();
  }

  int unreadCount() const { return m_unreadCount; }
  void setUnreadCount(int unreadCount)
  {
    m_unreadCount = unreadCount;
    emit unreadCountChanged();
  }

signals:
  void avatarChanged();
  void groupNameChanged();
  void messageChanged();
  void dateChanged();
  void isMuteChanged();
  void unreadCountChanged();

private:
  QString m_avatar;
  QString m_groupName;
  QString m_message;
  qint64 m_date;
  bool m_isMute;
  int m_unreadCount;
};

class ChatsController : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QList<ChatItem*> chatItemList READ chatItemList WRITE
               setChatItemList NOTIFY chatItemListChanged)
public:
  explicit ChatsController(QObject* parent = nullptr);

  QList<ChatItem*> chatItemList() const { return m_chatItemList; }
  void setChatItemList(const QList<ChatItem*>& chatItemList)
  {
    m_chatItemList = chatItemList;
    emit chatItemListChanged();
  }

  Q_INVOKABLE void prepend(ChatItem* chatItem)
  {
    m_chatItemList.prepend(chatItem);
    emit chatItemListChanged();
  }

signals:
  void chatItemListChanged();

private:
  QList<ChatItem*> m_chatItemList;
};

#endif // CHATSCONTROLLER_H

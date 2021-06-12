import Felgo 3.0
import QtQuick 2.0
import "./Page/Chats"
import "./Page/Contacts"
import "./Page/Discover"
import "./Page/Me"
import Common 1.0

App {
    id: app

    Navigation {
        navigationMode: navigationModeTabs

        NavigationItem {
            title: WString.chats
            iconComponent: Loader {
                readonly property string source_on: "../assets/active/chats.png"
                readonly property string source_off: "../assets/inactive/chats.png"
                sourceComponent: navigationItemComponent
            }

            NavigationStack {
                ChatsPage {
                    title: WString.chats
                }
            }
        } // chat

        NavigationItem {
            title: WString.contacts
            iconComponent: Loader {
                readonly property string source_on: "../assets/active/contacts.png"
                readonly property string source_off: "../assets/inactive/contacts.png"
                sourceComponent: navigationItemComponent
            }

            NavigationStack {
                ContactsPage {
                    title: WString.contacts
                }
            }
        } // contacts

        NavigationItem {
            title: WString.discover
            iconComponent: Loader {
                readonly property string source_on: "../assets/active/discover.png"
                readonly property string source_off: "../assets/inactive/discover.png"
                sourceComponent: navigationItemComponent
            }

            NavigationStack {
                DiscoverPage {
                    title: WString.discover
                }
            }
        } // discover

        NavigationItem {
            title: WString.me
            iconComponent: Loader {
                readonly property string source_on: "../assets/active/me.png"
                readonly property string source_off: "../assets/inactive/me.png"
                sourceComponent: navigationItemComponent
            }

            NavigationStack {
                MePage {
                    title: WString.me
                }
            }
        } // me
    }

    Component {
        id: navigationItemComponent
        Image {
            property bool isSelected: parent.parent && parent.parent.selected
            height: dp(20)
            fillMode: Image.PreserveAspectFit
            source: isSelected ? parent.source_on : parent.source_off
        }
    }
}

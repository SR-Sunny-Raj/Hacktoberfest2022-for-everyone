import sys
import threading

from PyQt5.QtCore import pyqtSignal, pyqtSlot, QObject
from PyQt5.QtGui import QPixmap
from PyQt5.QtWidgets import (
    QApplication,
    QComboBox,
    QLabel,
    QMainWindow,
    QPlainTextEdit,
)

from pynput.keyboard import Listener, Controller
import pyperclip as pc

class KeyboardListener(QObject):
    textChanged = pyqtSignal(str)
    def __init__(self, shortcut, parent=None):
        super().__init__(parent) 
        self._shortcut = shortcut
        listener = Listener(on_press=self.handle_pressed)
        listener.start()
        self.mutex = threading.Lock()

    @property
    def shortcut(self):
        return self._shortcut

    def handle_pressed(self, key):
        with self.mutex:
            if str(key) == self.shortcut:
                cptext = pc.paste()
                self.textChanged.emit(cptext)

    @pyqtSlot(str)
    def update_shortcut(self, shortcut):
        with self.mutex:
            self._shortcut = shortcut


class App(QMainWindow):
    def __init__(self, parent=None):
        super(App, self).__init__(parent)
        # super().__init__()
        label = QLabel(self)
        pixmap = QPixmap('E:\CopyCat\new.png')
        label.setPixmap(pixmap)
        label.setGeometry(0, 0, 530, 400)
        self.setFixedHeight(385)
        self.setFixedWidth(538)
        self.title = "COPYCAT"
        self.left = 10
        self.top = 10
        self.width = 400
        self.height = 140
        self.initUI()

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)
        ###########
        combo = QComboBox(self)
        shotcut_list = [
            "Key.f9",
            "Key.f2",
            "Key.f3",
            "Key.f4",
            "Key.f5",
            "Key.f6",
            "Key.f7",
            "Key.f8",
            "Key.f1",
            "Key.f10",
            "Key.f11",
            "Key.f12",
        ]
        combo.addItems(shotcut_list)
        shortcut = combo.currentText()
        combo.setGeometry(400, 120, 120, 30)
        self.textbox = QPlainTextEdit(self)
        self.textbox.setStyleSheet(
        """QPlainTextEdit {background-color: #333;
                           color: #7ad2e4;
                           font-family: Input;}""")
        self.textbox.move(20, 160)
        self.textbox.setReadOnly(True)
        self.textbox.resize(500, 205)
        self.textbox.insertPlainText("For Educational Purposes Only ⚆_⚆\n")
        self.setGeometry(70, 70, 540, 388)
        self.keyboard = Controller()
        self.listener = KeyboardListener(combo.currentText())
        combo.activated[str].connect(self.listener.update_shortcut)
        self.listener.textChanged.connect(self.handle_text_changed)

    @pyqtSlot(str)
    def handle_text_changed(self, text):
    
        self.textbox.insertPlainText(text)
        self.textbox.insertPlainText("\n")
        self.keyboard.type(text)

def main():
    app = QApplication(sys.argv)
    ex = App()
    ex.show()
    sys.exit(app.exec_())
    input("Hello")
if __name__ == "__main__":
    main()

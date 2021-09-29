import sys
from PyQt5.QtWidgets import QApplication, QMainWindow

import Ui_untitled

if __name__ == '__main__':
    app = QApplication(sys.argv)
    MainWindow = QMainWindow()
    ui = Ui_untitled.Ui_MainWindow()
    ui.setupUi(MainWindow)
    # ui.buton.setText("李文祖")
    MainWindow.show()
    sys.exit(app.exec_())
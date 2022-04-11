# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'cpsRecord.ui'
#
# Created by: PyQt5 UI code generator 5.15.4
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_recordDialog(object):
    def setupUi(self, recordDialog):
        recordDialog.setObjectName("recordDialog")
        recordDialog.resize(330, 266)
        recordDialog.setMinimumSize(QtCore.QSize(0, 266))
        self.verticalLayout = QtWidgets.QVBoxLayout(recordDialog)
        self.verticalLayout.setObjectName("verticalLayout")
        self.recordLabel = QtWidgets.QLabel(recordDialog)
        self.recordLabel.setAlignment(QtCore.Qt.AlignCenter)
        self.recordLabel.setObjectName("recordLabel")
        self.verticalLayout.addWidget(self.recordLabel)
        spacerItem = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.verticalLayout.addItem(spacerItem)
        self.nameLabel = QtWidgets.QLabel(recordDialog)
        self.nameLabel.setObjectName("nameLabel")
        self.verticalLayout.addWidget(self.nameLabel)
        self.filenameInput = QtWidgets.QLineEdit(recordDialog)
        self.filenameInput.setObjectName("filenameInput")
        self.verticalLayout.addWidget(self.filenameInput)
        self.destinationLabel = QtWidgets.QLabel(recordDialog)
        self.destinationLabel.setObjectName("destinationLabel")
        self.verticalLayout.addWidget(self.destinationLabel)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.pathBrowser = QtWidgets.QTextBrowser(recordDialog)
        self.pathBrowser.setMaximumSize(QtCore.QSize(16777215, 23))
        self.pathBrowser.setObjectName("pathBrowser")
        self.horizontalLayout_2.addWidget(self.pathBrowser)
        self.chooseButton = QtWidgets.QPushButton(recordDialog)
        self.chooseButton.setAutoDefault(False)
        self.chooseButton.setObjectName("chooseButton")
        self.horizontalLayout_2.addWidget(self.chooseButton)
        self.verticalLayout.addLayout(self.horizontalLayout_2)
        spacerItem1 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.verticalLayout.addItem(spacerItem1)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        spacerItem2 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout.addItem(spacerItem2)
        self.lengthLabel = QtWidgets.QLabel(recordDialog)
        self.lengthLabel.setObjectName("lengthLabel")
        self.horizontalLayout.addWidget(self.lengthLabel)
        self.lengthSpinBox = QtWidgets.QSpinBox(recordDialog)
        self.lengthSpinBox.setMaximumSize(QtCore.QSize(45, 16777215))
        self.lengthSpinBox.setMinimum(1)
        self.lengthSpinBox.setObjectName("lengthSpinBox")
        self.horizontalLayout.addWidget(self.lengthSpinBox)
        spacerItem3 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout.addItem(spacerItem3)
        self.verticalLayout.addLayout(self.horizontalLayout)
        spacerItem4 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.verticalLayout.addItem(spacerItem4)
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setContentsMargins(0, -1, 0, -1)
        self.horizontalLayout_3.setSpacing(0)
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        spacerItem5 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_3.addItem(spacerItem5)
        self.quitButton = QtWidgets.QPushButton(recordDialog)
        self.quitButton.setAutoDefault(False)
        self.quitButton.setObjectName("quitButton")
        self.horizontalLayout_3.addWidget(self.quitButton)
        spacerItem6 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_3.addItem(spacerItem6)
        self.recStopButton = QtWidgets.QPushButton(recordDialog)
        self.recStopButton.setObjectName("recStopButton")
        self.horizontalLayout_3.addWidget(self.recStopButton)
        spacerItem7 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_3.addItem(spacerItem7)
        self.verticalLayout.addLayout(self.horizontalLayout_3)

        self.retranslateUi(recordDialog)
        QtCore.QMetaObject.connectSlotsByName(recordDialog)

    def retranslateUi(self, recordDialog):
        _translate = QtCore.QCoreApplication.translate
        recordDialog.setWindowTitle(_translate("recordDialog", "Record"))
        self.recordLabel.setText(_translate("recordDialog", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">Record</span></p></body></html>"))
        self.nameLabel.setText(_translate("recordDialog", "Output file name:"))
        self.destinationLabel.setText(_translate("recordDialog", "Output file destination:"))
        self.chooseButton.setText(_translate("recordDialog", "Choose"))
        self.lengthLabel.setText(_translate("recordDialog", "Length of recording:"))
        self.quitButton.setText(_translate("recordDialog", "Back"))
        self.recStopButton.setText(_translate("recordDialog", "Record"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    recordDialog = QtWidgets.QDialog()
    ui = Ui_recordDialog()
    ui.setupUi(recordDialog)
    recordDialog.show()
    sys.exit(app.exec_())

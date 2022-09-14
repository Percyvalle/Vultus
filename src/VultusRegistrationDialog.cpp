#include "VultusRegistrationDialog.h"
#include "ui_VultusRegistrationDialog.h"

VultusRegistrationDialog::VultusRegistrationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VultusRegistrationDialog)
{
    ui->setupUi(this);

    initUI();
    connectionUI();
}

VultusRegistrationDialog::~VultusRegistrationDialog()
{
    delete ui;
}

void VultusRegistrationDialog::initUI()
{
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle(" ");
}

void VultusRegistrationDialog::connectionUI()
{
    connect(ui->authorization_button, &QPushButton::clicked, this, &VultusRegistrationDialog::clickedAuthorization);
}

void VultusRegistrationDialog::clickedAuthorization()
{
}

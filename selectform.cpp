#include "selectform.h"
#include "ui_selectform.h"

selectForm::selectForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectForm)
{
    ui->setupUi(this);
}

selectForm::~selectForm()
{
    delete ui;
}

void selectForm::on_planButton_clicked()
{
    emit planButton_clicked();
}

void selectForm::on_tripButton_clicked()
{
    emit tripButton_clicked();
}

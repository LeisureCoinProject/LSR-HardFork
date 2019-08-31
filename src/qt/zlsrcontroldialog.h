// Copyright (c) 2017-2019 The leisurecoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef zlsrCONTROLDIALOG_H
#define zlsrCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zlsr/zerocoin.h"
#include "privacydialog.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class zlsrControlDialog;
}

class CzlsrControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CzlsrControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CzlsrControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CzlsrControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class zlsrControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit zlsrControlDialog(QWidget *parent);
    ~zlsrControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::zlsrControlDialog *ui;
    WalletModel* model;
    PrivacyDialog* privacyDialog;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CzlsrControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // zlsrCONTROLDIALOG_H

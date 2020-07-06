/**
 * @file    CPatternsView.hpp
 * @author  vgoncharuk
 * @brief   Declaration of the CPatternsView class
 */

#ifndef CPATTERNSVIEW_HPP
#define CPATTERNSVIEW_HPP

#include <QTreeView>

#include "../common/Definitions.hpp"

class CTreeRepresentationDelegate;
class CPatternsModel;

class CPatternsView : public QTreeView
{
    Q_OBJECT

    typedef QTreeView tParent;

public:

    struct tCopyPastePatternItem
    {
        QString alias;
        QString regex;
    };

    typedef QVector<tCopyPastePatternItem> tCopyPastePatternItemsPack;

    struct tCopyPastePatternData
    {
        QString file;
        tCopyPastePatternItemsPack items;
    };

    explicit CPatternsView(QWidget *parent = nullptr);
    ~CPatternsView() override;

    virtual void scrollTo(const QModelIndex &index, ScrollHint hint) override;

    void setSpecificModel( CPatternsModel* pModel );
    void setPatternsSearchInput( QLineEdit* pPatternsSearchInput );

protected:
    bool eventFilter(QObject* pObj, QEvent* pEvent) override;

public slots:

    /*
     * @applyPatternsCombination - will apply selected pattern and start search with it.
     * Created, to easily trigger combined search from any other place within the plugin.
     */
    void applyPatternsCombination();

signals:
    void patternSelected( const QString& regexCandidate );
    void deletePatternTriggered();
    void editPatternTriggered();
    void overwriteFromInputFieldTriggered();
    void pastePatternTriggered(const tCopyPastePatternData& copyPastePatternData);

protected:
    virtual void keyPressEvent ( QKeyEvent* pEvent ) override;

private: // methods
    void setModel(QAbstractItemModel *model) override;
    QString createCombinedRegex();
    void updateColumnsVisibility();
    void copySelectedRow();
    void pasteSelectedRow();

private: // fields
    CTreeRepresentationDelegate * mpRepresentationDelegate;
    CPatternsModel* mpModel;
    QLineEdit* mpPatternsSearchInput;
    tCopyPastePatternData mCopyPastePatternData;
};
#endif // CPATTERNSVIEW_HPP

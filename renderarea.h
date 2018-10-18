#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    QSize minimumSizeHint() const;
    QSize SizeHint() const ;
    enum ShapeType{Astroid, Cycloid,HuygensCycloid,HypoCycloid,Line};
    void setBackgroundColor(QColor color){mBackgroundColor=color;}//setter
    QColor backgroundColor() const  {return mBackgroundColor;}            //getter
    void  setShapeColor(QColor color){mShapeColor=color;}
    QColor ShapeColor()const{return mShapeColor; }
    void setShape(ShapeType shape){mShape=shape;on_shape_changed();}
    ShapeType shape()const{return mShape;}
    void setScale(float scale){mScale=scale; repaint();}
    float scale() const{return mScale;}
    void setInterval(float interval){ mIntervalLength=interval; repaint();}
    float intervalLength() const{return mIntervalLength;}
   void setStepCount (int count) {mStepCount=count; repaint();}
   int stepCount() const{return mStepCount;}
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
   QPointF compute_Astroid(float t);
   QPointF compute_cycloid(float t);
   QPointF compute_huygens(float t);
   QPointF compute_hypo(float t);
   QPointF compute(float t); //dispatch function based on mshape type
   QPointF compute_line(float t);
   void on_shape_changed();
signals:

public slots:
private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;
    float  mIntervalLength;
    float mScale;
    int mStepCount;
};

#endif // RENDERAREA_H

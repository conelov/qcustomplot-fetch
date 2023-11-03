#include <QApplication>

#include <qcustomplot.h>


int main(int argc, char* argv[]) {
  QApplication app{argc, argv};

  QCustomPlot plot;
  {
    auto const grap = plot.addGraph();
    {
      auto pen = grap->pen();
      pen.setWidth(3);
      pen.setColor(Qt::blue);
      grap->setPen(pen);
    }
    constexpr auto resolution = 100;
    constexpr auto border     = 5 * resolution;
    for (auto i = -static_cast<int>(border); i < border; ++i) {
      auto const x = i / static_cast<double>(resolution);
      grap->addData(x, x * x);
    }
    grap->rescaleAxes();
  }
  plot.resize(640, 480);
  plot.show();

  return QApplication::exec();
}

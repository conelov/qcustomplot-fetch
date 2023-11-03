#include <QApplication>

#include "qcustomplot.h"


int main(int argc, char* argv[]) {
  QApplication app{argc, argv};

  QCustomPlot plot;
  {
    auto const grap = plot.addGraph();
    {
      auto pen = grap->pen();
      pen.setWidth(3);
      pen.setColor(Qt::red);
      grap->setPen(pen);
    }
    constexpr std::size_t resolution = 100;
    for (std::size_t i{}; i < M_PI * resolution * 2; ++i) {
      auto const x = i / static_cast<double>(resolution);
      grap->addData(x, std::sin(x));
    }
    grap->rescaleAxes();
  }
  plot.resize(640, 480);
  plot.show();

  return QApplication::exec();
}

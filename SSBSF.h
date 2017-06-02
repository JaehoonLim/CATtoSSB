// Copy of CATTools/CommonTools/*/ScaleFactorEvaluator

#include <cassert>
#include <vector>
#include <utility>
#include <algorithm>

class ScaleFactorEvaluator
{
public:
  ScaleFactorEvaluator();
  ~ScaleFactorEvaluator();
  void set(const std::vector<double>& xbins,
           const std::vector<double>& ybins,
           const std::vector<double>& values,
           const std::vector<double>& errors);
  double get(double x, double y, double shift = 0);
  
private:
  std::vector<double> xbins_, ybins_;
  std::vector<double> values_;
  std::vector<double> errors_;

  int width_;
};

ScaleFactorEvaluator::ScaleFactorEvaluator(){
}
ScaleFactorEvaluator::~ScaleFactorEvaluator(){
}

void ScaleFactorEvaluator::set(const std::vector<double>& xbins,
                               const std::vector<double>& ybins,
                               const std::vector<double>& values,
                               const std::vector<double>& errors)
{
  xbins_ = xbins;
  ybins_ = ybins;
  values_ = values;
  errors_ = errors;

  const unsigned int n = (xbins.size()-1)*(ybins.size()-1);
  // FIXME : check that these bins are monolothically increasing
  assert(values.size() == n);
  assert(errors.size() == n);

  // For cache
  width_ = xbins_.size()-1;
}

double ScaleFactorEvaluator::get(double x, const double y, const double shift)
{
  auto xbin = std::lower_bound(xbins_.begin(), xbins_.end(), x);
  if ( xbin == xbins_.end() or xbin+1 == xbins_.end() ) return 1;
  auto ybin = std::lower_bound(ybins_.begin(), ybins_.end(), y);
  if ( ybin == ybins_.end() or ybin+1 == ybins_.end() ) return 1;

  const int column = xbin-xbins_.begin();
  const int row = ybin-ybins_.begin();

  const int bin = row*width_+column;
  const double value = values_.at(bin);
  const double error = errors_.at(bin);

  return std::max(0.0, value+shift*error);
}


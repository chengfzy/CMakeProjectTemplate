#include <string>
#include "opencv2/features2d.hpp"

namespace feaext {

class FeatureExtractor {
   public:
    explicit FeatureExtractor(int featureNums = 300);
    ~FeatureExtractor() = default;

   public:
    std::vector<cv::KeyPoint> extract(const std::string& file);

   private:
    cv::Ptr<cv::Feature2D> featureDetector_;
};

}  // namespace feaext
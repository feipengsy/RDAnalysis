#include "JetFitObject.h"
#include "LeptonFitObject.h"
#include "BaseFitter.h"
#include "NewtonFitterGSL.h"
#include "OPALFitterGSL.h"
#include "MomentumConstraint.h"
#include "SoftGaussMassConstraint.h"
#include "MassConstraint.h"
#include <Rtypes.h>
#include <TError.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>
#include <new>
#include <numeric>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>
//#include "ROOT/RVec.hxx"


namespace Kinfit{

float fit(JetFitObject j1,JetFitObject j2,LeptonFitObject l1,LeptonFitObject l2);
float BeforeFit(JetFitObject j1,JetFitObject j2,LeptonFitObject l1,LeptonFitObject l2);
float fourlep(LeptonFitObject l1,LeptonFitObject l2,LeptonFitObject l3,LeptonFitObject l4);
//std::vector<JetFitObject> getJet(ROOT::VecOps::RVec<float> px,ROOT::VecOps::RVec<float> py,ROOT::VecOps::RVec<float> pz,ROOT::VecOps::RVec<float> energy);

}

#include "../api/Definitions.hpp"

tRequestParameters::tRequestParameters():
pFile(nullptr),
fromMessage(0),
numberOfMessages(0),
regex(),
numberOfThreads(0),
isContinuous(false)
{
}

tRequestParameters::tRequestParameters(
const tFileWrapperPtr& pFile_,
const int& fromMessage_,
const int& numberOfMessages_,
const QRegularExpression& regex_,
const int& numberOfThreads_,
bool isContinuous_):
pFile(pFile_),
fromMessage(fromMessage_),
numberOfMessages(numberOfMessages_),
regex(regex_),
numberOfThreads(numberOfThreads_),
isContinuous(isContinuous_)
{
}

tProgressNotificationData::tProgressNotificationData():
requestId(INVALID_REQUEST_ID),
requestState(eRequestState::ERROR_STATE),
progress(0),
processedMatches(),
bUML_Req_Res_Ev_DuplicateFound(false)
{
}

tProgressNotificationData::tProgressNotificationData(
const tRequestId& requestId_,
const eRequestState& requestState_,
const int8_t& progress_,
const tFoundMatchesPack& processedMatches_,
bool bUML_Req_Res_Ev_DuplicateFound_):
requestId(requestId_),
requestState(requestState_),
progress(progress_),
processedMatches(processedMatches_),
bUML_Req_Res_Ev_DuplicateFound(bUML_Req_Res_Ev_DuplicateFound_)
{
}

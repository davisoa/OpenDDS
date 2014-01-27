#include "DataWriterListenerImpl.h"
#include "common.h"
#include "../common/SampleInfo.h"
#include "dds/DdsDcpsPublicationC.h"
#include "dds/DCPS/Service_Participant.h"

DataWriterListenerImpl::DataWriterListenerImpl ()
: test_failed_(false)
, test_valid_(false)
{
}

// Implementation skeleton destructor
DataWriterListenerImpl::~DataWriterListenerImpl ()
{
}

void DataWriterListenerImpl::on_offered_deadline_missed (
      ::DDS::DataWriter_ptr writer,
      const ::DDS::OfferedDeadlineMissedStatus & status
    )
{
  ACE_UNUSED_ARG(writer) ;
  ACE_UNUSED_ARG(status) ;
}

void DataWriterListenerImpl::on_offered_incompatible_qos (
      ::DDS::DataWriter_ptr writer,
      const ::DDS::OfferedIncompatibleQosStatus & status
    )
{
  ACE_UNUSED_ARG(writer) ;
  ACE_UNUSED_ARG(status) ;

  test_failed_ = true;

  ACE_ERROR ((LM_ERROR,
         "(%P|%t) DataWriterListenerImpl::on_offered_incompatible_qos "
         "All QOS should be compatible for this test\n"));
}

void DataWriterListenerImpl::on_liveliness_lost (
      ::DDS::DataWriter_ptr writer,
      const ::DDS::LivelinessLostStatus & status
    )
{
  ACE_UNUSED_ARG(writer) ;
  ACE_UNUSED_ARG(status) ;
}

void DataWriterListenerImpl::on_publication_matched (
      ::DDS::DataWriter_ptr writer,
      const ::DDS::PublicationMatchedStatus & status
    )
{
  ACE_UNUSED_ARG(writer) ;
  ACE_UNUSED_ARG(status) ;

  test_valid_ = true;

  ACE_DEBUG((LM_DEBUG,
    ACE_TEXT("(%P|%t) DataReaderListenerImpl::on_publication_matched \n")));
}

void DataWriterListenerImpl::on_publication_disconnected (
      ::DDS::DataWriter_ptr writer,
      const ::OpenDDS::DCPS::PublicationDisconnectedStatus & status
    )
{
  ACE_UNUSED_ARG(writer) ;
  ACE_UNUSED_ARG(status) ;
}

void DataWriterListenerImpl::on_publication_reconnected (
      ::DDS::DataWriter_ptr writer,
      const ::OpenDDS::DCPS::PublicationReconnectedStatus & status
    )
{
  ACE_UNUSED_ARG(writer) ;
  ACE_UNUSED_ARG(status) ;
}

void DataWriterListenerImpl::on_publication_lost (
      ::DDS::DataWriter_ptr writer,
      const ::OpenDDS::DCPS::PublicationLostStatus & status
    )
{
  ACE_UNUSED_ARG(writer) ;
  ACE_UNUSED_ARG(status) ;
}

void DataWriterListenerImpl::on_connection_deleted (
      ::DDS::DataWriter_ptr writer
    )
{
  ACE_UNUSED_ARG(writer) ;
}

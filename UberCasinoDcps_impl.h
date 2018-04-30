#ifndef UBERCASINODCPS_IMPL_H_
#define UBERCASINODCPS_IMPL_H_

#include "ccpp.h"
#include "ccpp_UberCasino.h"
#include "ccpp_TypeSupport_impl.h"
#include "ccpp_DataWriter_impl.h"
#include "ccpp_DataReader_impl.h"
#include "ccpp_DataReaderView_impl.h"


namespace UberCasino {

    class  PlayerTypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        PlayerTypeSupportFactory() {}
        virtual ~PlayerTypeSupportFactory() {}
    private:
        ::DDS::DataWriter_ptr
        create_datawriter (gapi_dataWriter handle);
    
        ::DDS::DataReader_ptr
        create_datareader (gapi_dataReader handle);
    
        ::DDS::DataReaderView_ptr
        create_view (gapi_dataReaderView handle);
    };
    
    class  PlayerTypeSupport : public virtual PlayerTypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type(
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name() THROW_ORB_EXCEPTIONS;
    
        PlayerTypeSupport (void);
        virtual ~PlayerTypeSupport (void);
    
    private:
        PlayerTypeSupport (const PlayerTypeSupport &);
        void operator= (const PlayerTypeSupport &);
    
        static const char *metaDescriptor[];
        static const ::DDS::ULong metaDescriptorArrLength;
    };
    
    typedef PlayerTypeSupportInterface_var PlayerTypeSupport_var;
    typedef PlayerTypeSupportInterface_ptr PlayerTypeSupport_ptr;
    
    class  PlayerDataWriter_impl : public virtual PlayerDataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance(
            const Player & instance_data) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp(
            const Player & instance_data,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance(
            const Player & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp(
            const Player & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write(
            const Player & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp(
            const Player & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose(
            const Player & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp(
            const Player & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t writedispose(
            const Player & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t writedispose_w_timestamp(
            const Player & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value(
            Player & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t lookup_instance(
            const Player & instance_data) THROW_ORB_EXCEPTIONS;
    
    
        PlayerDataWriter_impl (
            gapi_dataWriter handle
        );
    
        virtual ~PlayerDataWriter_impl (void);
    
    private:
        PlayerDataWriter_impl(const PlayerDataWriter_impl &);
        void operator= (const PlayerDataWriter &);
    };
    
    class  PlayerDataReader_impl : public virtual PlayerDataReader,
                                        public ::DDS::DataReader_impl
    {
        friend class PlayerDataReaderView_impl;
    public:
        virtual ::DDS::ReturnCode_t read(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_w_condition(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_w_condition(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample(
            Player & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample(
            Player & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_instance(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_instance(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value(
            Player & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t lookup_instance(
            const Player & instance) THROW_ORB_EXCEPTIONS;
    
        PlayerDataReader_impl (
            gapi_dataReader handle
        );
    
        virtual ~PlayerDataReader_impl(void);
    
    private:
        PlayerDataReader_impl(const PlayerDataReader &);
        void operator= (const PlayerDataReader &);
    
        static ::DDS::ReturnCode_t check_preconditions(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples
        );
    };
    
    class  PlayerDataReaderView_impl : public virtual PlayerDataReaderView,
                                        public ::DDS::DataReaderView_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_w_condition(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_w_condition(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample(
            Player & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample(
            Player & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_instance(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_instance(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan(
            PlayerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value(
            Player & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t lookup_instance(
            const Player & instance) THROW_ORB_EXCEPTIONS;
    
        PlayerDataReaderView_impl (
            gapi_dataReader handle
        );
    
        virtual ~PlayerDataReaderView_impl(void);
    
    private:
        PlayerDataReaderView_impl(const PlayerDataReaderView &);
        void operator= (const PlayerDataReaderView &);
    };
    
    class  DealerTypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        DealerTypeSupportFactory() {}
        virtual ~DealerTypeSupportFactory() {}
    private:
        ::DDS::DataWriter_ptr
        create_datawriter (gapi_dataWriter handle);
    
        ::DDS::DataReader_ptr
        create_datareader (gapi_dataReader handle);
    
        ::DDS::DataReaderView_ptr
        create_view (gapi_dataReaderView handle);
    };
    
    class  DealerTypeSupport : public virtual DealerTypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type(
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name() THROW_ORB_EXCEPTIONS;
    
        DealerTypeSupport (void);
        virtual ~DealerTypeSupport (void);
    
    private:
        DealerTypeSupport (const DealerTypeSupport &);
        void operator= (const DealerTypeSupport &);
    
        static const char *metaDescriptor[];
        static const ::DDS::ULong metaDescriptorArrLength;
    };
    
    typedef DealerTypeSupportInterface_var DealerTypeSupport_var;
    typedef DealerTypeSupportInterface_ptr DealerTypeSupport_ptr;
    
    class  DealerDataWriter_impl : public virtual DealerDataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance(
            const Dealer & instance_data) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp(
            const Dealer & instance_data,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance(
            const Dealer & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp(
            const Dealer & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write(
            const Dealer & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp(
            const Dealer & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose(
            const Dealer & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp(
            const Dealer & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t writedispose(
            const Dealer & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t writedispose_w_timestamp(
            const Dealer & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value(
            Dealer & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t lookup_instance(
            const Dealer & instance_data) THROW_ORB_EXCEPTIONS;
    
    
        DealerDataWriter_impl (
            gapi_dataWriter handle
        );
    
        virtual ~DealerDataWriter_impl (void);
    
    private:
        DealerDataWriter_impl(const DealerDataWriter_impl &);
        void operator= (const DealerDataWriter &);
    };
    
    class  DealerDataReader_impl : public virtual DealerDataReader,
                                        public ::DDS::DataReader_impl
    {
        friend class DealerDataReaderView_impl;
    public:
        virtual ::DDS::ReturnCode_t read(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_w_condition(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_w_condition(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample(
            Dealer & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample(
            Dealer & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_instance(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_instance(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value(
            Dealer & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t lookup_instance(
            const Dealer & instance) THROW_ORB_EXCEPTIONS;
    
        DealerDataReader_impl (
            gapi_dataReader handle
        );
    
        virtual ~DealerDataReader_impl(void);
    
    private:
        DealerDataReader_impl(const DealerDataReader &);
        void operator= (const DealerDataReader &);
    
        static ::DDS::ReturnCode_t check_preconditions(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples
        );
    };
    
    class  DealerDataReaderView_impl : public virtual DealerDataReaderView,
                                        public ::DDS::DataReaderView_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_w_condition(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_w_condition(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample(
            Dealer & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample(
            Dealer & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_instance(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_instance(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan(
            DealerSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value(
            Dealer & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t lookup_instance(
            const Dealer & instance) THROW_ORB_EXCEPTIONS;
    
        DealerDataReaderView_impl (
            gapi_dataReader handle
        );
    
        virtual ~DealerDataReaderView_impl(void);
    
    private:
        DealerDataReaderView_impl(const DealerDataReaderView &);
        void operator= (const DealerDataReaderView &);
    };
    
    class  GameTypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        GameTypeSupportFactory() {}
        virtual ~GameTypeSupportFactory() {}
    private:
        ::DDS::DataWriter_ptr
        create_datawriter (gapi_dataWriter handle);
    
        ::DDS::DataReader_ptr
        create_datareader (gapi_dataReader handle);
    
        ::DDS::DataReaderView_ptr
        create_view (gapi_dataReaderView handle);
    };
    
    class  GameTypeSupport : public virtual GameTypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type(
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name() THROW_ORB_EXCEPTIONS;
    
        GameTypeSupport (void);
        virtual ~GameTypeSupport (void);
    
    private:
        GameTypeSupport (const GameTypeSupport &);
        void operator= (const GameTypeSupport &);
    
        static const char *metaDescriptor[];
        static const ::DDS::ULong metaDescriptorArrLength;
    };
    
    typedef GameTypeSupportInterface_var GameTypeSupport_var;
    typedef GameTypeSupportInterface_ptr GameTypeSupport_ptr;
    
    class  GameDataWriter_impl : public virtual GameDataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance(
            const Game & instance_data) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp(
            const Game & instance_data,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance(
            const Game & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp(
            const Game & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write(
            const Game & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp(
            const Game & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose(
            const Game & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp(
            const Game & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t writedispose(
            const Game & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t writedispose_w_timestamp(
            const Game & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value(
            Game & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t lookup_instance(
            const Game & instance_data) THROW_ORB_EXCEPTIONS;
    
    
        GameDataWriter_impl (
            gapi_dataWriter handle
        );
    
        virtual ~GameDataWriter_impl (void);
    
    private:
        GameDataWriter_impl(const GameDataWriter_impl &);
        void operator= (const GameDataWriter &);
    };
    
    class  GameDataReader_impl : public virtual GameDataReader,
                                        public ::DDS::DataReader_impl
    {
        friend class GameDataReaderView_impl;
    public:
        virtual ::DDS::ReturnCode_t read(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_w_condition(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_w_condition(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample(
            Game & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample(
            Game & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_instance(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_instance(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value(
            Game & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t lookup_instance(
            const Game & instance) THROW_ORB_EXCEPTIONS;
    
        GameDataReader_impl (
            gapi_dataReader handle
        );
    
        virtual ~GameDataReader_impl(void);
    
    private:
        GameDataReader_impl(const GameDataReader &);
        void operator= (const GameDataReader &);
    
        static ::DDS::ReturnCode_t check_preconditions(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples
        );
    };
    
    class  GameDataReaderView_impl : public virtual GameDataReaderView,
                                        public ::DDS::DataReaderView_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_w_condition(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_w_condition(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample(
            Game & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample(
            Game & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_instance(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_instance(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan(
            GameSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value(
            Game & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t lookup_instance(
            const Game & instance) THROW_ORB_EXCEPTIONS;
    
        GameDataReaderView_impl (
            gapi_dataReader handle
        );
    
        virtual ~GameDataReaderView_impl(void);
    
    private:
        GameDataReaderView_impl(const GameDataReaderView &);
        void operator= (const GameDataReaderView &);
    };
    
}

#endif

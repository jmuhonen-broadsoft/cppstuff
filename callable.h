
#include <QObject>

namespace Utils
{
	template< class A >
	class Callable
	{
		private:
			Callable();

			A * m_A;

		public:
			Callable( A * a )
				: m_A( a )
			{}

			template< class B >
			Callable< B > get( B*(A::*getter)() const ) const
			{
				B * b = NULL;
				if ( m_A )
					b = (m_A->*getter)();
				return Callable< B >( b );
			}

			template< class B >
			Callable< B > get( B*(A::*getter)() )
			{
				B * b = NULL;
				if ( m_A )
					b = (m_A->*getter)();
				return Callable< B >( b );
			}

			template< class C >
			Callable< C > get( QObject*(A::*getter)() const ) const
			{
				C * c = NULL;
				if ( m_A )
					c = qobject_cast< C * >( (m_A->*getter)() );
				return Callable< C >( c );
			}

			template< class C >
			Callable< C > get( QObject*(A::*getter)() )
			{
				C * c = NULL;
				if ( m_A )
					c = qobject_cast< C * >( (m_A->*getter)() );
				return Callable< C >( c );
			}

			template< class B, class C >
			Callable< C > get( B*(A::*getter)() const ) const
			{
				C * c = NULL;
				if ( m_A )
					c = static_cast< C * >( (m_A->*getter)() );
				return Callable< C >( c );
			}

			template< class B, class C >
			Callable< C > get( B*(A::*getter)() )
			{
				C * c = NULL;
				if ( m_A )
					c = static_cast< C * >( (m_A->*getter)() );
				return Callable< C >( c );
			}

			template< class B >
			Callable< A > & set( void(A::*setter)(B), B b )
			{
				if ( m_A )
					(m_A->*setter)( b );
				return *this;
			}

			template< class B, class C, class D >
			Callable< A > & set( void(A::*setter)(B, C), B b, C c, D d )
			{
				if ( m_A )
					(m_A->*setter)( b, c, d );
				return *this;
			}

			template< class B, class C, class D, class E >
			Callable< A > & set( void(A::*setter)(B, C), B b, C c, D d, E e )
			{
				if ( m_A )
					(m_A->*setter)( b, c, d, e );
				return *this;
			}

			template< class B, class C, class D, class E, class F >
			Callable< A > & set( void(A::*setter)(B, C), B b, C c, D d, E e, F f )
			{
				if ( m_A )
					(m_A->*setter)( b, c, d, e, f );
				return *this;
			}

			template< class B, class C, class D, class E, class F, class G >
			Callable< A > & set( void(A::*setter)(B, C), B b, C c, D d, E e, F f, G g )
			{
				if ( m_A )
					(m_A->*setter)( b, c, d, e, f, g );
				return *this;
			}
			

			template< class B >
			B value( B(A::*getter)() )
			{
				if ( m_A )
					return (m_A->*getter)();
				return B();
			}

			template< class B >
			B value( B(A::*getter)() const ) const
			{
				if ( m_A )
					return (m_A->*getter)();
				return B();
			}

			template< class B >
			Callable< B > qcast() const
			{
				return Callable< B >( qobject_cast< B * >( m_A ));
			}

			operator A *()
			{
				return m_A;
			}

			operator const A * () const
			{
				return m_A;
			}

			A * operator->()
			{
				return m_A;
			}

			const A * operator->() const
			{
				return m_A;
			}
	};
} /*Utils*/

#if 0
	QString name = Callable< SCP::Controllers::CommunicationSession >( session )
		.get< QObject >( &SCP::Controllers::CommunicationSession::getContact )
		.qcast< SCP::Contacts::IContact >()
		.value< QString >( &SCP::Contacts::IContact::getName );

	name = Callable< SCP::Controllers::CommunicationSession >( session )
		.get< SCP::Contacts::IContact >( &SCP::Controllers::CommunicationSession::getContact )
		.value< QString >( &SCP::Contacts::IContact::getName );

	const SCP::Controllers::CommunicationSession * s = session;
	Callable< SCP::Controllers::ChatInterface > ci = Callable< const SCP::Controllers::CommunicationSession >( s )
		.get< SCP::Controllers::ChatInterface >( &SCP::Controllers::CommunicationSession::getChat );

	Callable< SCP::Controllers::CommunicationSession >( session )
		.set< SCP::Actions::Provider * >( &SCP::Controllers::CommunicationSession::setActionsProvider, NULL )
		.set( &SCP::Controllers::CommunicationSession::setActionsProvider, (SCP::Actions::Provider *)NULL )
		.value< bool >( &SCP::Controllers::CommunicationSession::getCallRecordingEnabled );
	 if ( ci )
		 ci->setContact( NULL );
#endif
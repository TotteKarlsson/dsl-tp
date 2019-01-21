//
// SessionImpl.h
//
// $Id: //poco/Main/Data/testsuite/src/SessionImpl.h#2 $
//
// Definition of the SessionImpl class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Data_Test_SessionImpl_INCLUDED
#define Data_Test_SessionImpl_INCLUDED


#include "Poco/Data/AbstractSessionImpl.h"
#include "Poco/SharedPtr.h"
#include "Binder.h"


namespace Poco {
namespace Data {
namespace Test {


class SessionImpl: public Poco::Data::AbstractSessionImpl<SessionImpl>
	/// A no-op implementation of SessionImpl for testing.
{
public:
	SessionImpl(const std::string& init,
		std::size_t timeout = LOGIN_TIMEOUT_DEFAULT);
		/// Creates the SessionImpl. Opens a connection to the database.

	~SessionImpl();
		/// Destroys the SessionImpl.

	Poco::Data::StatementImpl* createStatementImpl();
		/// Returns an test StatementImpl.

	void open(const std::string& connectionString = "");
		/// Opens the session.

	void close();
		/// Closes the session.

	bool isConnected();
		/// Returns true if session is connected to the database, 
		/// false otherwise.

	void setConnectionTimeout(std::size_t timeout);
		/// Sets the session connection timeout value.

	std::size_t getConnectionTimeout();
		/// Returns the session connection timeout value.

	void begin();
		/// Starts a transaction.

	void commit();
		/// Commits and ends a transaction.

	void rollback();
		/// Aborts a transaction.

	bool canTransact();
		/// Returns true if session has transaction capabilities.

	bool isTransaction();
		/// Returns true iff a transaction is a transaction is in progress, false otherwise.

	void setTransactionIsolation(Poco::UInt32);
		/// Sets the transaction isolation level.

	Poco::UInt32 getTransactionIsolation();
		/// Returns the transaction isolation level.

	bool hasTransactionIsolation(Poco::UInt32);
		/// Returns true iff the transaction isolation level corresponding
		/// to the supplied bitmask is supported.

	bool isTransactionIsolation(Poco::UInt32);
		/// Returns true iff the transaction isolation level corresponds
		/// to the supplied bitmask.

	const std::string& connectorName();
		/// Returns the name of the connector.

	void setConnected(const std::string& name, bool value);
	bool getConnected(const std::string& name);
		/// Sets/gets the connected property.
		/// This is normally done by implementation
		/// when a database connection loss is detected.

	void setF(const std::string& name, bool value);
	bool getF(const std::string& name);
	void setP(const std::string& name, const Poco::Any& value);
	Poco::Any getP(const std::string& name);

private:
	bool         _f;
	Poco::Any    _p;
	bool         _connected;
	std::string  _connectionString;
};


} } } // namespace Poco::Data::Test


#endif // Data_Test_SessionImpl_INCLUDED

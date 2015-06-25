Messages Between Elixir and C++
===============================

Send [MessagePack][0] messages from [Elixir][1] to C++ through [nanomsg][2].

[0]: http://msgpack.org/
[1]: http://elixir-lang.org/
[2]: http://nanomsg.org/


Overview
--------

There is a Elixir application in `elixir_client` and a C++ application in
`cpp_server`. Elixir sends MessagePack encoded messages through nanomsg to a
Qt/C++ application. The C++ application is a GUI application that shows the
received messages in a windows (Qt TextArea) as a string.

Prerequisites
-------------

* Qt installation (tested with version 5.4).
* nanomsg installation. It is important to use the same version as that is shipped with `basho/enm`. Currently 0.5-beta.
* MessagePack installation (tested with Debian package `libmsgpack-dev`).


Usage
-----

C++. This compiles and start the GUI application.

~~~
cd cpp_server
qmake .
make
./cpp_server
~~~

Elixir. This fetches, compiles and starts the Erlang/Elixir applications.

~~~
cd elixir_client
mix deps.get
mix deps.compile
iex -S mix
~~~

Once we are in the Elixir shell, we can start sending messages to the C++ program.

~~~
{:ok, s} = :enm.pair
:enm.connect(s, "ipc:///tmp/test.ipc")
:enm.send(s, [<<1>> | Msgpax.pack!(["hey", "hoo"])])
:enm.close
~~~

## Initial interface idea

### genkey

Key generation outside of the actual agent/client, allowing the dev to place the client's key
on the server without actually running the client.

`rlisten genkey <seed/identity>`

Which should output something like this:

```
Public Key: <hex-encoded-supercop-pubkey>
Secret Key: <hex-encoded-supercop-seckey>
```

### Agent

Basically the entrypoint for a browser's point of view

`rlisten agent [--config /etc/rlisten/rlisten.conf] [--daemon]`

```
# /etc/rlisten/rlisten.conf

# Our server's identity
# Used as seed to generate ed25519 keypair
# Generates /etc/rlisten/pubkey, which is a hex-encoded supercop format ed25519 public key
identity = <string>

# OPTIONAL
# Letsencrypt certificate generation
# Only generates/refreshes certs for currently-active names (because client configs contain wildcards)
acme:letsencrypt = webmaster@example.com

# Named client key directory
client-dir = /etc/rlisten/client

# Where certificates are stored for tls-enabled connections
cert-dir = /etc/letsencrypt/live

# Which IP to use when listening for sockets requested by clients
bind-client = 0.0.0.0

# Which IP to use when serving our own api
# Can be the same as the client listener (uses port 9910)
bind-api = 192.168.0.100

# Keep peers in a separate file by default
# Allows symlink to synced folder for easy removal of a server
include /etc/rlisten/peers.conf
```

```
# /etc/rlisten/peers.conf

# Simply a set of peers to connect to
# Connected peers will listen for our clients as well (even if they don't know the client)
peer = <hex-encoded-pubkey> 192.168.0.110
peer = <hex-encoded-pubkey> peer-00.example.com
```

```
# /etc/rlisten/client/<name>.conf

# ed25519 key, hex-encoded supercop format
# allows us to verify the client's signature
pubkey = <client public key>

# allow specific protocols to be used by the client
# port 9910 is NEVER allowed for clients, as that's our api port
# default = <none>
protocol = ssl

# we can also limit which ports the client can listen on
# default = <protocol-default>
protocol = ssl:443

# allow specific SNI names to be used by the client
# prevents authenticated clients from listening on names/domains they're not allowed to
name = example.com
name = *.example.com

# If a client needs bare tcp listening (so no ssl+sni which provides us with a name),
# the client will need access to ANY name (as we don't support filtering the protocol)
protocol = tcp:22
name = *
```

### Client

The receiving side of requests

```
rlisten client --agent agent.example.com --identity <client-seed/identity> --name example.com [--proto ssl:443] --target 127.0.0.1:5000
rlisten client --agent agent.example.com --identity <client-seed/identity> --name example.com [--proto ssl:443] --exec executable -- arg [...arg]
```

### Brainstorm

- add quark httpd as static host, so we can say `--docroot /path/to/docs`?
- consul support (already knows services + hostnames + ports, only need names and/or tags)

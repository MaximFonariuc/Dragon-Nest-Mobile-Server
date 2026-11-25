# Deployment security notes

## Administrative listeners

The GM tool listeners in `exe/conf/login_conf.xml` (port 25002) and
`exe/conf/version_conf.xml` (port 24002) are bound to `127.0.0.1` by default.
Keep them private. If remote administration is required, use a VPN or SSH tunnel
rather than exposing these ports directly to the public internet.

## Database credentials

The sample configuration uses the MySQL `root` account with an empty password.
That is suitable only for an isolated local test environment. Before any network
deployment:

1. Set a strong password for the MySQL administrative account.
2. Create a dedicated database account with only the permissions required by
   the server databases.
3. Update every applicable `<DB>` and `<OnlineDB>` entry under `exe/conf/`.
4. Keep database port 3306 private and do not expose it to the public internet.

## Public listeners and transport

The client-facing listeners bind to `0.0.0.0` in the sample configuration.
Expose only the ports required by the client and restrict all other ports with
the host firewall and cloud security group.

The gate configuration currently has `<Encrypt enabled="0"/>`. Do not enable
it blindly: confirm that the matching client build supports the same protocol
settings first. Until then, treat the network as untrusted and avoid using
real credentials or sensitive personal data.

## Account credentials

Do not reuse the sample account credentials for a public deployment. Use unique
credentials and verify the server's password hashing and account-creation flow
before importing or changing account records.

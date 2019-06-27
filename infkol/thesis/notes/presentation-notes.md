# Presentation Notes

## Intro
- We wanted to what OAuth really is and more importantly what it isn't
- Simply put, OAuth is a protocol 
    - that is used to grant third-party applications limited access 
    - to protected resources 
    - on behalf of a resource owner

## Roles
- The entities involved here are
    - Resource Owner: Entity that grants access to protected resources.
    - Resource Server: Server that hosts the protected resources. Handles the requests to protected resources using access tokens.
    - Client: Application that sends requests to retrieve protected resources on behalf of the resource owner, once it has been granted authorization.
    - Authorization Server: Server that supplies access tokens to a client after the resource owner has been authenticated and has obtained authorization.

## Token
- So as you can see the access token provides the right to access a requested protected resource
- The token mostly only grants limited access to delegate a specific range of action

## The Problem before OAuth
- Before we look at the OAuth protocol flow, I would like to look at how this problem has been tackled in the past
- There were many approaches like
    - Credential Sharing, were the client would copy the resource owner's credentials and replay them to the protected resource. The problem here is that the resource owner exposes his credentials and the client is impersonating the user
    - Or, the use of a universal key, that grants access. The problem here is if the key is stolen the resources are exposed.
    - Or, a special password. This just means yet another password to remember.

## OAuth 2.0
- OAuth lets users grant limited and fine-graned access to their protected resources separately for different clients. 
- This requires an authorization server.
- The flow looks like this
    1. An application (client) sends an authorization request directly to a resource owner, or, preferably, indirectly through an authorization server.
    2. The client is authorized and receives a grant which represents the resource owner’s authorization credentials.
    3. The client can now request an access token from the authorization server with the freshly obtained grant.
    4. The client is then authenticated by the authorization server once it has suc- cessfully validated the authorization grant. Then the authorization server creates and issues an access token.
    5. The client can now request protected resources from the resource server with the access token.
    6. If the access token has been successfully validated, the resource server pro- vides the client with the requested resources.

- It is important to note that these access tokens can be reused, often within a specific time scope (expiration time, etc.)

- There are many kind of ways how such a token can be created
    - not implementing safe tokens can often lead to vulnerabilities
    - an example of an unsafe token would be an unsigned token that is merely base64 encoded and as the name suggests "unsigned"
    - luckily there are industry standards such as the JSON Web Token
    - https://jwt.io/

.. -*- rst -*-

========================
 OS-ENDPOINT-POLICY API
========================

Creates, verifies, and deletes associations between service
endpoints and policies. Such associations enable an endpoint to
request its policy.

To create, check, or delete an association, you reference a policy
by its ID in the Identity server.

The extension supports these associations:

- A policy and endpoint association.

- A policy and service-type endpoint in a region association.

- A policy and service-type endpoint association.

This order reflects policies in their most to least-specific order.

When an endpoint requests the appropriate policy for itself, the
extension finds the policy by traversing the ordered sequence of
methods of association. The extension shows the policy for the
first association that it finds.

If the region of the endpoint has a parent, the extension examines
the region associations up the region tree in ascending order. For
region associations, the extension examines any parent regions in
ascending order. The extension does not combine polices.


Associate policy and endpoint
=============================

.. rest_method::  PUT /v3/policies/{policy_id}/OS-ENDPOINT-POLICY/endpoints/{endpoint_id}

Associates a policy and an endpoint.

If an association already exists between the endpoint and another
policy, this call replaces that association.

Normal response codes: 204

Request
-------

.. rest_parameters:: parameters.yaml

   - policy_id: policy_id
   - endpoint_id: endpoint_id


Verify a policy and endpoint association
========================================

.. rest_method::  GET /v3/policies/{policy_id}/OS-ENDPOINT-POLICY/endpoints/{endpoint_id}

Verifies an association between a policy and an endpoint.

A HEAD version of this API is also supported.

Normal response codes: 204

Request
-------

.. rest_parameters:: parameters.yaml

   - policy_id: policy_id
   - endpoint_id: endpoint_id


Delete a policy and endpoint association
========================================

.. rest_method::  DELETE /v3/policies/{policy_id}/OS-ENDPOINT-POLICY/endpoints/{endpoint_id}

Deletes an association between a policy and an endpoint.

Normal response codes: 204

Request
-------

.. rest_parameters:: parameters.yaml

   - policy_id: policy_id
   - endpoint_id: endpoint_id


Associate policy and service-type endpoint
==========================================

.. rest_method::  PUT /v3/policies/{policy_id}/OS-ENDPOINT-POLICY/services/{service_id}

Associates a policy and any endpoint of a service type.

If an association already exists between the endpoint of a service
type and another policy, this call replaces that association.

Normal response codes: 204

Request
-------

.. rest_parameters:: parameters.yaml

   - policy_id: policy_id
   - service_id: service_id


Verify a policy and service-type endpoint association
=====================================================

.. rest_method::  GET /v3/policies/{policy_id}/OS-ENDPOINT-POLICY/services/{service_id}

Verifies an association between a policy and an endpoint of a service type.

A HEAD version of this API is also supported.

Normal response codes: 204

Request
-------

.. rest_parameters:: parameters.yaml

   - policy_id: policy_id
   - service_id: service_id


Delete a policy and service-type endpoint association
=====================================================

.. rest_method::  DELETE /v3/policies/{policy_id}/OS-ENDPOINT-POLICY/services/{service_id}

Deletes an association between a policy and an endpoint of a service type.

Normal response codes: 204

Request
-------

.. rest_parameters:: parameters.yaml

   - policy_id: policy_id
   - service_id: service_id


Show policy for endpoint
========================

.. rest_method::  GET /v3/policies/{policy_id}/OS-ENDPOINT-POLICY/policy

Shows a policy for an endpoint.

The extension finds the policy by traversing the ordered sequence
of methods of association. The extension shows the policy for the
first association that it finds. If the region of the endpoint has
a parent, the extension examines the region associations up the
region tree in ascending order.

Normal response codes: 200

Request
-------

.. rest_parameters:: parameters.yaml

   - policy_id: policy_id

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - policy: policy
   - type: type
   - blob: blob
   - links: links
   - id: id

Response Example
----------------

.. literalinclude:: samples/OS-ENDPOINT-POLICY/policy-show-response.json
   :language: javascript


Check policy and service endpoint association
=============================================

.. rest_method::  HEAD /v3/policies/{policy_id}/OS-ENDPOINT-POLICY/policy

Checks whether a policy is associated with an endpoint.

Normal response codes: 200

Request
-------

.. rest_parameters:: parameters.yaml

   - policy_id: policy_id


Associate policy and service-type endpoint in a region
======================================================

.. rest_method::  PUT /v3/policies/{policy_id}/OS-ENDPOINT-POLICY/services/{service_id}/regions/{region_id}

Associates a policy and an endpoint of a service type in a region.

If an association already exists between the service in a region
and another policy, this call replaces that association.

Normal response codes: 204

Request
-------

.. rest_parameters:: parameters.yaml

   - policy_id: policy_id
   - service_id: service_id
   - region_id: region_id


Verify a policy and service-type endpoint in a region association
=================================================================

.. rest_method::  GET /v3/policies/{policy_id}/OS-ENDPOINT-POLICY/services/{service_id}/regions/{region_id}

Verifies an association between a policy and service-type endpoint in a region.

A HEAD version of this API is also supported.

Normal response codes: 204

Request
-------

.. rest_parameters:: parameters.yaml

   - policy_id: policy_id
   - service_id: service_id
   - region_id: region_id


Delete a policy and service-type endpoint in a region association
=================================================================

.. rest_method::  DELETE /v3/policies/{policy_id}/OS-ENDPOINT-POLICY/services/{service_id}/regions/{region_id}

Deletes an association between a policy and service-type endpoint in a region.

Normal response codes: 204

Request
-------

.. rest_parameters:: parameters.yaml

   - policy_id: policy_id
   - service_id: service_id
   - region_id: region_id


List policy and service endpoint associations
=============================================

.. rest_method::  GET /v3/policies/{policy_id}/OS-ENDPOINT-POLICY/endpoints

Lists all the endpoints that are currently associated with a policy through any of the association methods.

Normal response codes: 200

Request
-------

.. rest_parameters:: parameters.yaml

   - policy_id: policy_id

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - links: links
   - url: url
   - region: region
   - next: next
   - self: self
   - interface: interface
   - service_id: service_id
   - endpoints: endpoints
   - id: id
   - previous: previous

Response Example
----------------

.. literalinclude:: samples/OS-ENDPOINT-POLICY/policy-endpoint-associations-list-response.json
   :language: javascript


Show the effective policy associated with an endpoint
=====================================================

.. rest_method:: GET /v3/endpoints/{endpoint_id}/OS-ENDPOINT-POLICY/policy

Returns the policy that is currently associated with the given endpoint, by
working through the ordered sequence of methods of association. The first
association that is found will be returned. If the region of the endpoint has a
parent, then region associations will be examined up the region tree in
ascending order.

A HEAD version of this API is also supported.

Normal response codes: 200

Request
-------

.. rest_parameters:: parameters.yaml

   - endpoint_id: endpoint_id

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - policy: policy
   - type: type
   - blob: blob
   - links: links
   - id: id

Response Example
----------------

.. literalinclude:: samples/OS-ENDPOINT-POLICY/policy-show-response.json
   :language: javascript

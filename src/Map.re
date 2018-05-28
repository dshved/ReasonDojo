[@bs.module "react-simple-maps"]
external composableMap : ReasonReact.reactClass = "ComposableMap";

[@bs.module "react-simple-maps"]
external zoomableGroup : ReasonReact.reactClass = "ZoomableGroup";

[@bs.module "react-simple-maps"]
external geographies : ReasonReact.reactClass = "Geographies";

[@bs.module "react-simple-maps"]
external geographyComponent : ReasonReact.reactClass = "Geography";

[@bs.module "react-simple-maps"]
external markerComponent : ReasonReact.reactClass = "Marker";

[@bs.module "react-simple-maps"]
external markersComponent : ReasonReact.reactClass = "Markers";

module ComposableMap = {
  [@bs.deriving abstract]
  type jsProps = {
    width: int,
    height: int,
  };
  let make = (~width, ~height, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=composableMap,
      ~props=jsProps(~width, ~height),
      children,
    );
};

module ZoomableGroup = {
  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass=zoomableGroup,
      ~props=Js.Dict.empty(),
      children,
    );
};

module Geographies = {
  [@bs.deriving abstract]
  type jsProps = {geography: string};
  [@bs.deriving abstract]
  type geography = {id: string};
  type projection;
  let make = (~geography, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=geographies,
      ~props=jsProps(~geography),
      children,
    );
};

module Geography = {
  [@bs.deriving abstract]
  type jsProps = {
    geography: Geographies.geography,
    projection: Geographies.projection,
  };
  let make = (~geography, ~projection, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=geographyComponent,
      ~props=jsProps(~geography, ~projection),
      children,
    );
};

type coordinates = (float, float);

module MarkerData = {
  [@bs.deriving abstract]
  type marker = {coordinates};
};

module Marker = {
  [@bs.deriving abstract]
  type jsProps = {marker: MarkerData.marker};
  let make = (~marker, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=markerComponent,
      ~props=jsProps(~marker),
      children,
    );
};

module Markers = {
  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass=markersComponent,
      ~props=Js.Dict.empty(),
      children,
    );
};
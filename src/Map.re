module ComposableMap = {
  [@bs.module "react-simple-maps"]
  external reactClass : ReasonReact.reactClass = "ComposableMap";

  [@bs.deriving abstract]
  type jsProps = {
    width: int,
    height: int,
  };
  let make = (~width, ~height, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=jsProps(~width, ~height),
      children,
    );
};

module ZoomableGroup = {
  [@bs.module "react-simple-maps"]
  external reactClass : ReasonReact.reactClass = "ZoomableGroup";

  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=Js.Dict.empty(),
      children,
    );
};

module Geographies = {
  [@bs.module "react-simple-maps"]
  external reactClass : ReasonReact.reactClass = "Geographies";

  [@bs.deriving abstract]
  type jsProps = {geography: string};
  [@bs.deriving abstract]
  type geography = {id: string};
  type projection;
  let make = (~geography, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=jsProps(~geography),
      children,
    );
};

module Geography = {
  [@bs.module "react-simple-maps"]
  external reactClass : ReasonReact.reactClass = "Geography";

  [@bs.deriving abstract]
  type jsProps = {
    geography: Geographies.geography,
    projection: Geographies.projection,
  };
  let make = (~geography, ~projection, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
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
  [@bs.module "react-simple-maps"]
  external reactClass : ReasonReact.reactClass = "Marker";

  [@bs.deriving abstract]
  type jsProps = {marker: MarkerData.marker};
  let make = (~marker, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=jsProps(~marker),
      children,
    );
};

module Markers = {
  [@bs.module "react-simple-maps"]
  external reactClass : ReasonReact.reactClass = "Markers";

  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=Js.Dict.empty(),
      children,
    );
};
